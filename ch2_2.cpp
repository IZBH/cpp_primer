#include <iostream>

int main()
{
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl;
    // 将-42转换为无符号数，再加10，即：(UINT_MAX + i + 1) + u
    std::cout << u + i << std::endl;
}