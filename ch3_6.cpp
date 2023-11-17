#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void func1() {
    string str("some string");

    for (auto c: str) {
        cout << c << endl;
    }
}

void func2() {
    string s("Hello World!!!");

    decltype(s.size()) punct_cnt = 0;
    for (auto c: s) {
        if (ispunct(c))
            punct_cnt++;
    }

    cout << punct_cnt
         << " punctuation characters in " << s << endl;
}

void func3() {
    string s("Hello World!!!");
    for (auto &c: s) {
        c = toupper(c);
    }

    cout << s << endl;
}

void func4() {
    string s("some string");
    if (!s.empty())
        s[0] = toupper(s[0]);
    cout << s << endl;
}

void func5(){
    string s("some string");
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) {
        s[index] = toupper(s[index]);
    }
    cout << s << endl;
}

int main() {
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of number between 0 and 15"
        << " separated by spaces. Hit ENTER when finished: "
        << endl;

    string result;
    string ::size_type n;

    while (cin >> n){
        if (n < hexdigits.size()){
            result += hexdigits[n];
        }
    }

    cout << "Your hex number is: " << result << endl;
}