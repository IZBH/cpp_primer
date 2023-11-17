#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void func1() {
    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;
    s1 += s2;
}

void func2() {
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + '\n';
    string s4 = s1 + ", ";
    //string对象和字符字面值以及字符串字面值混在一条语句中使用时，
    // 必须确保每个加法运算符（+）两次的运算对象至少有一个是string、
    //错误
    //string s5 = "hello" + ", ";
    string s6 = s1 + ", " + "world";
    //错误
    //string s7 = "hello" + ", " + s2;
}

int main() {
}