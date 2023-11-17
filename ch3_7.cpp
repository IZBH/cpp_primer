#include "Sales_item.h"
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void func1() {
    vector<int> ivec;            //ivec保存int类型的对象
    vector<Sales_item> Sales_vec;//保存Sales_item类型的对象
    vector<vector<string>> file; //该向量的元素是vector对象
}

void func2() {
    /**
     * vector<T> v1                 //v1是一个空vector,他的潜在元素的类型是T类型，执行默认初始化
     * vector<T> v2(v1)             //v2中包含v1所有元素的副本
     * vector<T> v2 = v1            //等价于v2(v1)，v2中包含v1所有元素的副本
     * vector<T> v3(n, val)         //v3中包含了n个重复的元素，每个元素的值都是val
     * vector<T> v4(n)              //v4包含了n个重复的执行了值初始化的对象
     * vector<T> v5{a,b,c...}       //v5包含了初始值个数的元素，每个元素被赋予相应的初始值
     * vector<T> v5={a,b,c...}      //等价于v5{a,b,c...}
     */

    vector<string> articles = {"a", "an", "the"};
    //vector<string> articles_error = ("a", "an", "the");
    vector<int> ivec(10, -1);
    vector<string> svec(10, "hi");
}

void func3() {
    vector<int> ivec(10);   //10个元素，每个都初始化为0
    vector<string> svec(10);//10个元素，每个都是空string对象
    //vector<int> vi = 10;                 //错误：必须使用直接初始化的形式指定向量大小
    vector<int> v1(10);   //v1有10个元素，每个都是0
    vector<int> v2{10};   //v2有1个元素，该元素的值是10
    vector<int> v3(10, 1);//v3有10个元素，每个都是1
    vector<int> v4{10, 1};//v4有两个元素，值分别是0和1


    vector<string> v5{"hi"};//列表初始化，v5有一个元素
    //vector<string> v6("hi");              //错误：不能使用字符串字面值构建vector对象
    vector<string> v7{10};      //v7有10个默认初始化的元素
    vector<string> v8{10, "hi"};//v8有10个值为"hi"的元素
}

void func4() {
    vector<vector<int>> ivec;
    //vector<string> svec = ivec;
    vector<string> svec(10, "null");
}

void func5() {
    vector<int> v2;//空vector
    //依次把整数值放到v2尾端
    for (int i = 0; i != 100; ++i) {
        v2.push_back(i);
    }
}

void func6() {
    //从标准输入中提取单词，并将其作为vector对象的元素存储ui
    string word;
    vector<string> text;
    while (cin >> word) {
        text.push_back(word);
    }
}

void func7() {
    /**
     * vector<int> v, v1, v2;
     * int i, n;
     * v.empty();                   //如果v不含有任何元素，返回真；否则返回假
     * v.size();                    //返回v中元素的个数
     * v.push_back(i);              //向v的尾端添加为一个值为t的元素
     * v[n];                        //返回v中第n个位置上元素的引用
     * v1 = v2;                     //用v2中元素的拷贝替换v1中的元素
     * v1 = {a,b,c...};             //用列表中元素的拷贝替换v1中的元素
     * v1 == v2;                    //v1和v2相等且仅当他们的元素数量相同且对应位置的元素值都相同
     * v1 != v2;
     * <, <=, >, >=
     */
}

void func8() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //i是v中元素的引用
    for (auto &i: v) {
        i *= i;
    }
    //输出v中的每个元素
    for (auto i: v) {
        cout << i << " ";
    }

    cout << endl;
}

void func9() {
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }

    for (auto i: scores) {
        cout << i << " ";
    }
    cout << endl;
}

void func10() {
    vector<int> ivec;
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) {
        //ivec[ix] = ix;    //错误，ivec不包含元素，不能使用下标访问任何元素
        //vector对象以及string对象的下标运算符可用于访问已存在的元素，而不能用于添加元素。
        ivec.push_back(ix);
    }

    for (auto &i: ivec) {
        cout << i << " ";
    }
}


int main() {
    func10();
}
