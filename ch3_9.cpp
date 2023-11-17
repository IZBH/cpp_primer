#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
    int arr[10];

    int *ptr_s1[10];    //ptr_s是含有10个整形指针的数组
    //int &refs[10];      //不存在引用的数组
    int (*p_array)[10] = &arr; //p_array指向一个含有10个整数的数组
}