#include <iostream>

int main()
{
    const int ci = 1024;
    const int &r1 = ci;
    //r1 = 42; //error
    //int &r2 = ci; //error
}