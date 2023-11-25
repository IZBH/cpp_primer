#include <iostream>
#include <string>
#include <vector>


using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

/**
 * 混用string对象和c风格字符串
 * 允许使用以空字符结束的字符数组来初始化string对象或为string对象赋值
 * 在string对象的加法运算中允许使用以空字符结束的字符数组作为其中一个运算对象(不能两个都是)
 * 在string对象的复合赋值运算中允许使用以空字符结束的字符数组作为右侧的运算对象
 */
void func1() {
    string s("Hello World");//s的内容是 Hello World
    //    char *str = s;                 //错误:不能使用string对象初始化char *
    const char *str1 = s.c_str();//正确
}

/**
 * 使用数组初始化vector对象
 * 不允许使用一个数组为另一个内置类型的数组赋初值
 * 不允许使用vector对象初始化数组
 * 允许使用数组来初始化vector对象
 */
void func2() {
    int int_arr[] = {0, 1, 2, 3, 4, 5, 6};
    vector<int> ivec(begin(int_arr), end(int_arr));

    for (int i = 0; i < sizeof(int_arr) / sizeof(*int_arr); ++i) {
        cout << int_arr[i] << endl;
    }

    for (auto i: ivec) {
        cout << i << endl;
    }
}

/**
 * 多维数组,c++没有多维数组,多维数组是数组的数组
 */
void func3() {
    int ia[3][4];//大小为3的数组,每个元素是含有四个整数的数组

    /**
     * 大小为10的数组,每个元素都是大小为20的数组
     * 这些数组的元素是含有30个整数的数组
     */
    int arr[10][20][30] = {0};
}

void func4() {
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
    };

    int ia1[3][4] = {
            0,
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8,
            9,
            10,
            11,
    };

    int ia2[3][4] = {{0}, {4}, {8}};

    int ia3[3][4] = {0, 3, 6, 9};
}

void func5() {
    int arr[10][20][30] = {0};
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
    };
    ia[2][3] = arr[0][0][0];

    //将row定义成一个含有四个整数数组的引用,然后将其绑定到ia的第二行
    int(&row)[4] = ia[1];//把row绑定到ia的第2个4元素数组上(即第二行)
}

void fun6() {
    constexpr size_t rowCnt = 3, colCnt = 4;

    int ia[rowCnt][colCnt];

    for (int i = 0; i != rowCnt; ++i) {
        for (int j = 0; j != colCnt; ++j) {
            ia[i][j] = i * colCnt + j;
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;

    //使用范围for语句时,除了最内层的循环外,其他所有循环的控制变量都应该是引用类型
    size_t cnt = 0;
    for (auto &row: ia) {
        for (auto &col: row) {
            cout << col << " ";
        }
    }
    cout << endl;
}

void func7() {
    //大小为3的数组,每个元素是含有4个整数的数组
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
    };
    //p指向含有四个整数的数组
    int(*p)[4] = ia;
    //p指向ia的尾元素
    p = &ia[2];

    /**
     * int *pi[4];  //整形指针组成的数组
     * int (*pi)[4];    //指向含有四个整数的数组的指针
     */

    //使用auto或者decltype声明,更加简洁
    for (auto p1 = ia; p1 != ia + 3; ++p1) {
        for (auto q1 = *p1; q1 != *p1 + 4; ++q1) {
            cout << *q1 << ' ';
        }
        cout << endl;
    }

    for (auto p2 = begin(ia); p2 != end(ia); ++p2) {
        for (auto q2 = begin(*p2); q2 != end(*p2); ++q2) {
            cout << *q2 << ' ';
        }
        cout << endl;
    }
}

void func8() {
    //大小为3的数组,每个元素是含有4个整数的数组
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
    };

    //创建新数据类型
    using int_array = int[4];
    //    typedef int int_array[4];

    for (int_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << ' ';
        }

        cout << endl;
    }
}

void func9() {
    //大小为3的数组,每个元素是含有4个整数的数组
    int ia[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
    };

    //创建新数据类型
    //    using int_array = int[4];
    typedef int int_array[4];

    for (int_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << ' ';
        }

        cout << endl;
    }
}


int main() {
    func9();
}