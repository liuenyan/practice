/**
 * 敏捷软件开发,第 13 章中的 Active Object 模式的 C++ 实现
 */
#include <iostream>
#include "CommandEngine.h"
#include "Command.h"
#include "DelayedTyper.h"


int main()
{
    CommandEngine engine;
    DelayedTyper d1 = DelayedTyper(100, '1', engine);
    DelayedTyper d2 = DelayedTyper(300, '2', engine);
    DelayedTyper d3 = DelayedTyper(500, '3', engine);
    DelayedTyper d4 = DelayedTyper(700, '4', engine);

    engine.addCommand(&d1);
    engine.addCommand(&d2);
    engine.addCommand(&d3);
    engine.addCommand(&d4);

    engine.run();
    
    return 0;
}
