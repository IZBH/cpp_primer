#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void func1() {
    int arr[10];

    //从右向左依次绑定:定义一个大小为10的数组->名字是ptrs->类型是int*
    int *ptr_s1[10];//ptr_s是含有10个整形指针的数组
    //int &refs[10];      //不存在引用的数组
    //先看括号内,*p_array->p_array是一个指针->p_array是指向大小为10的数组的指针->数组中的元素是int类型
    //所以,p_array是一个指针,该指针指向一个int[10]类型的数组
    int(*p_array)[10] = &arr;//p_array指向一个含有10个整数的数组
}

void func2() {
    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade / 10];
    }

    for (auto i: scores) {
        cout << i << " ";
    }

    cout << endl;
}

void func3() {
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //ia2的类型是int*
    auto ia2(ia);
    //ia3是一个由10个数构成的数组
    decltype(ia) ia3;
}

void func4() {
    int ia[] = {0, 1, 2, 3};
    //首元素的指针
    int *beg = std::begin(ia);
    //指向arr尾元素的下一位置的指针
    int *last = std::end(ia);
    cout << *beg << ", " << *(last - 1) << endl;
}

void func5() {
    int arr[] = {0, 1, 2, 3, 4, 5, -1};

    int *p_beg = std::begin(arr);
    int *p_end = std::end(arr);

    for (; p_beg != p_end && *p_beg >= 0; ++p_beg) {
        cout << *p_beg << ", ";
    }

    cout << "found it: " << *p_beg << endl;
}

int main() {
    func5();
}