#ifndef INDEX_MIN_PQ_H_INCLUDED
#define INDEX_MIN_PQ_H_INCLUDED

#include <iostream>
#include <memory>
#include <vector>

// 索引的最小优先级队列实现, 参考《算法(第四版)》 Robert Sedgewick & Kevin Wayne

template <typename KeyType>
class IndexMinPQ {
    int N_; // 堆中元素的数量
    std::vector<int> pq_; // 索引二叉堆, 由 1 开始
    std::vector<int> qp_; // 逆序 pq_[qp_[i]] == qp_[pq_[i]] == i
    std::vector<std::shared_ptr<KeyType>> keys_; // 有优先级之分的元素

public:
    IndexMinPQ(int maxN)
        : N_(0)
        , pq_(maxN + 1, 0)
        , qp_(maxN + 1, -1)
        , keys_(maxN + 1, 0){};
    bool Empty() const { return N_ == 0; };
    bool Contains(int k) const { return qp_[k] != -1; };
    std::shared_ptr<KeyType> Min() const { return keys_[pq_[1]]; };
    int MinIndex() const { return pq_[1]; };

    // 插入一个值
    void Insert(int k, std::shared_ptr<KeyType> key)
    {
        N_++;
        pq_[N_] = k;
        qp_[k] = N_;
        keys_[k] = key;
        swim(N_);
    };

    // 删除堆顶元素, 返回被删除的索引
    int DelMin()
    {
        int index_of_min = pq_[1];
        exch(1, N_--);
        sink(1);
        keys_[pq_[N_ + 1]] = nullptr;
        qp_[pq_[N_ + 1]] = -1;
        return index_of_min;
    };

    // 修改堆中的元素
    void Change(int k, std::shared_ptr<KeyType> key)
    {
        keys_[k] = key;
        swim(qp_[k]);
        sink(qp_[k]);
    }

    // 删除堆中的元素
    void Delete(int k)
    {
        int index = qp_[k];
        exch(index, N_--);
        swim(index);
        sink(index);
        keys_[k] = nullptr;
        qp_[k] = -1;
    }

private:
    // 上浮操作
    void swim(int k)
    {
        while (k > 1 && greater(k / 2, k)) {
            exch(k / 2, k);
            k = k / 2;
        }
    };
    // 下沉操作
    void sink(int k)
    {
        while (2 * k <= N_) {
            int j = 2 * k;
            if (j < N_ && greater(j, j + 1)) {
                j++;
            }
            if (greater(k, j)) {
                exch(k, j);
            }
            k = j;
        }
    };
    // 交换操作
    void exch(int i, int j)
    {
        // 交换反向索引
        qp_[pq_[i]] = j;
        qp_[pq_[j]] = i;
        // 交换堆中的索引
        int t = pq_[i];
        pq_[i] = pq_[j];
        pq_[j] = t;
    };
    // 比较操作
    bool greater(int i, int j)
    {
        return *keys_[pq_[i]] > *keys_[pq_[j]];
    };
};

#endif
