#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void func1() {
    string s("some string");
    if (s.begin() != s.end()) {//确保s非空
        auto it = s.begin();   //it表示s的第一个字符
        *it = toupper(*it);    //将当前字符更改为大写
    }

    cout << s << endl;
}

void func2() {
    string s("some string");
    //在c++中使用 != 而非 < ,因为这种编程风格在标准库上提供的所有容器都有效
    //所有的标准库容器的迭代器都定义了==和!=,但是大多数没有
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }

    cout << s << endl;
}

void func3() {
    vector<int>::iterator it;//it能读写vector<int>的元素
    string::iterator it2;    //it2能读写string对象中的字符

    vector<int>::const_iterator it3;//it3只能读,不能写
    string::const_iterator it4;     //it4只能读,不能写
}

void func4() {
    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();
    auto it2 = cv.begin();
    auto it3 = v.cbegin();
}

void func5() {
    vector<string> v_string{"hello", "world"};
    auto it = v_string.begin();
    (*it).empty();
    //*it.empty();
    it->empty();
}

void func6() {
    vector<string> text{"hello", "world"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }
}

void func7() {
    /** 类似于指向数组的指针
     * vector<int> iter;
     * iter + n
     * iter - n
     * iter += n
     * iter -= n
     * iter1 - iter2
     * >,>=,<,<=
     */

    vector<int> i_vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto iter1 = i_vec.begin();
    auto iter2 = i_vec.end();

    cout << *iter1 << endl;
    cout << *(iter2 - 1) << endl;
    cout << *(iter1 + 4) << endl;
    cout << *(iter2 - 4) << endl;
    cout << iter2 - iter1 << endl;
    cout << iter1 - iter2 << endl;

    iter1 += 1;
    iter2 -= 1;
    cout << *iter1 << endl;
    cout << *iter2 << endl;

    cout << iter2 - iter1 << endl;
    cout << iter1 - iter2 << endl;

    if (iter2 > iter1) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

void func8(int sought){
    vector<int> i_vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto beg = i_vec.begin(), end = i_vec.end();
    auto mid = i_vec.begin() + (end - beg) / 2;

    while (mid != end && *mid != sought){
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg)/2;
    }
    cout << *beg << endl;
    cout << *mid << endl;
    cout << *end << endl;
}

int main() {
    func8(2);
}