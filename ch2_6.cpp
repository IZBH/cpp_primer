#include <iostream>

int main()
{
    int i = 1024, i2 = 2048;
    int &r = i, r2 = i2;
    int i3 = 1024, &ri = i3;
    int &r3 = i3, &r4 = i2;

    // int &refVal4 = 10;
    double dval = 3.14;
    // int  &refVal5 = dval;
}