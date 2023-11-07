#include <iostream>

int reused = 42;

int main()
{
    int unique = 0;
    // 访问全局变量 reused
    std::cout << reused << " " << unique << std::endl;

    int reused = 0;
    // 访问局部变量 reused
    std::cout << reused << " " << unique << std::endl;

    std::cout << ::reused << " " << unique << std::endl;

    return 0;
}