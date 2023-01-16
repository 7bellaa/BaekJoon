#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    stack<int> a;
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            a.push(x);
        }
        else if (s == "pop") {
            if (a.empty()) cout << -1 << '\n';
            else {cout << a.top() << '\n'; a.pop();};
        }
        else if (s == "size") {
            cout << a.size() << '\n';
        }
        else if (s == "empty") {
            cout << (int)a.empty() << '\n';
        }
        else {
            if (a.empty()) cout << -1 << '\n';
            else cout << a.top() << '\n';
        }
    }
    return 0;
}