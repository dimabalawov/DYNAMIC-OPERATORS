
#include "DynamicArray.h"
#include <iostream>

int main()
{
    DynamicArray a(6);
    DynamicArray b(2);
    b.Input();
    b.Output();
    a.Input();
    a.Output();
    DynamicArray res = a + 2;
    res.Output();
    DynamicArray res2 = a - 2;
    res2.Output();
    DynamicArray res3 = a*10;
    res3.Output();
    DynamicArray res4 = a + b;
    res4.Output();
    DynamicArray res5 = a - b;
    res5.Output();
    DynamicArray res6=++a;
    res6.Output();
    DynamicArray res7=--a;
    res7.Output();
}