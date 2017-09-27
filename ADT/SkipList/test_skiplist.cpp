#include "SkipList.hpp"
#include <iostream>

using namespace std;
using namespace sl;

int main()
{
    int arr[] = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16
    };
    SkipList<int, int> sl;

    for (int i=0; i<16; i++) {
        sl.insert(new int(arr[i]), new int(arr[i]));
    }
    sl.print();
    cout << "--------" << endl;
    sl.remove(&arr[1]);
    sl.print();
    auto pv = sl.find(&arr[1]);
    if(pv) {
        cout << *pv << endl;
    } else {
        cout << "NULL" << endl;
    }
    auto pv2 = sl.find(&arr[8]);
    if(pv2) {
        cout << *pv2 << endl;
    } else {
        cout << "NULL" << endl;
    }
    return 0;
}
