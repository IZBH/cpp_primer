#include <iostream>

int main()
{
    //top-level const（顶层const）表示指针本身是个常量
    //low-level const（底层const）表示指针所指的对象是个常量
    int i = 0;
    int *const p1 = &i;         //top
    const int ci = 42;          //top
    const int *p2 = &ci;        //low
    const int *const p3 = p2;   //右边top,左边low
    const int &r = ci;          //low，声明引用的const都是底层const

    i = ci;
    p2 = p3;

    //int *p = p3;//error,p3包含底层定义，p无,更改如下
    const int *p = p3;
    p2 = p3;
    p2 = &i;
    //int &r = ci;//普通的引用不能绑定到int常量
    const int &r2 = i;
}