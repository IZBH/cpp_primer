#include <iostream>

int test()
{
    //引用被用作初始化时，真正参与初始化的时引用对象的值
    //引用以引用对象的类型作为auto的类型
    int i = 0, &r = i;
    auto a = r;

    //auto会忽略顶层const,同时会保留底层const
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    //如果希望推断出的auto类型是一个顶层const，需要明确指出
    const auto f = ci;

    //将引用的类型设为auto
    auto &g = ci;
    //auto &h = 42;
    const auto &j = 42;

}

int main()
{
    auto i = 0, *p = &i;

}