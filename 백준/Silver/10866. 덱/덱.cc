#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    deque<int> q;
    int n, x;
    cin >> n;
    while (n--) {
        string s; cin >> s;
        if (s == "push_back") {
            cin >> x;
            q.push_back(x);
        }
        else if (s == "push_front") {
            cin >> x;
            q.push_front(x);
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            cout << (int)q.empty() << '\n';
        }
        else if (q.empty()){
            cout << "-1\n";
        }
        else {
            if (s == "pop_front") {
                cout << q.front() << '\n';
                q.pop_front();
            }
            else if (s == "pop_back") {
                cout << q.back() << '\n';
                q.pop_back();
            }
            else if (s == "front") {
                cout << q.front() << '\n';
            }
            else if (s == "back") {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}