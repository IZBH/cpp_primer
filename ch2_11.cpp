#include <iostream>

int j = 0;
constexpr int k = 42;

int main()
{
    //常量表达式指不会改变且在编译过程就能得到计算结果的表达式
    //将变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式

    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    //constexpr int sz = size()//当size是一个constexpr函数时，才是一条正确的声明语句

    const int *p = nullptr;     //p是一个指向整形常量的指针
    constexpr int *q = nullptr;     //q是一个指向整数的常量指针

    //由于i在栈上申请，其地址不固定，因此使用constexpr修饰的指针不能指向i
    int i = 0;
    constexpr int *pi = &i;

    constexpr int *np = nullptr;    //np是一个指向整数类型的常量指针，值为空
    constexpr const int *pk = &k;   //pk是常量指针，指向整形常量k
    constexpr int *p1 = &j;         //p1时常量指针，指向整数j
}