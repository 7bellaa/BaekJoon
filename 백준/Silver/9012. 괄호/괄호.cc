#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        stack<char> a;
        bool flag = true;

        for (auto i : s) {
            if (i == ')') {
                if (!a.empty() && a.top() == '(') a.pop();
                else {flag = false; break;}
            }
            else a.push(i);
        }
        if (flag && a.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}