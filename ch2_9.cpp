#include <iostream>

int main()
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    // int &r4 = r1 * 2; //error,r4是一个普通的非常量应用

    //初始化常量引用时，允许使用任意表达式作为初始值
    //使用ri绑定临时对象
    double dval = 3.14;
    const int &ri = dval;
    //等价于
    const int temp = dval;
    const int &ri0 = temp;
}