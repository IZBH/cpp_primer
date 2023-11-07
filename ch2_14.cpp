#include <iostream>

int main()
{
    int i = 42, *p = &i, &r = i;
    //a为int &
    decltype(r) i_a = i;
    //b为int
    decltype(r + 0) i_b;
    //c为int &
    decltype(*p) i_c = i;

    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d= a;
    ++c;
    ++d;

    decltype(a) e = a;
    decltype(a = b) f= a;
}