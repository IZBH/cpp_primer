#include <iostream>
#include <math.h>

int main()
{
    float i;
    //编译器分析表达式 decltype(sin(i)) 的类型，并不实际计算表达式的值
    decltype(sin(i)) sum ;

    //decltype处理顶层const和引用的方式与auto不同
    //如果decltype使用的表达式是一个变量，则decltype该变量的类型(包括顶层const和引用)

    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;
    decltype(cj) y= x;
    //引用从来都是作为其所指对象的同义词出现，只有在decltype时例外
    //cj是一个引用，decltype(cj)的结果时引用类型，因此作为引用z的必须被初始化
    //decltype(cj) z



}