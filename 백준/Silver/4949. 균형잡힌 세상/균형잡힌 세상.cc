#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    while (1) {
        string s;
        getline(cin, s);
        if (s == ".") break;

        stack<char> a;
        bool flag = true;
        for (auto i : s) {
            if (i == '(' || i == '[') a.push(i);

            else if (i == ')') {
                if (a.empty() || a.top() != '(') {
                    flag = false;
                    break;
                }
                a.pop();
            }

            else if (i == ']') {
                if (a.empty() || a.top() != '[') {
                    flag = false;
                    break;
                }
                a.pop();
            }
        }
        if (flag && a.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}