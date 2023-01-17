#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    queue<int> q;
    string s;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q.push(x);
        }
        else if (s == "pop") {
            if (q.empty()) cout << "-1\n";
            else {cout << q.front() << '\n'; q.pop();}
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            cout << (int)q.empty() << '\n';
        }
        else if (s == "front") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        }
        else {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
    }
    return 0;
}