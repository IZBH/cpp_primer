#include <iostream>

int main()
{
    int ival = 1024;
    int &refVal = ival;
    //int &refVal2;错误，引用必须被初始化

    refVal = 2;
    int ii = refVal;

    int &refVal3 = refVal;
    int i = refVal;
}