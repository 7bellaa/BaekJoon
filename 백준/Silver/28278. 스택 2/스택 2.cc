#include <bits/stdc++.h>
using namespace std;

stack<int> s;

void push(int x) {
    s.push(x);
}

void pop_print() {
    if (!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }
    else cout << -1 << '\n';
}

void size() {
    cout << s.size() << '\n';
}

void empty() {
    cout << s.empty() << '\n';
}

void top() {
    if (!s.empty()) cout << s.top() << '\n';
    else cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while (N--) {
        int op; cin >> op;
        switch (op) {
            case 1: {
                int x; cin >> x;
                push(x);
                break;
            }
            case 2: {
                pop_print();
                break;
            }
            case 3: {
                size();
                break;
            }
            case 4: {
                empty();
                break;
            }
            case 5: {
                top();
                break;
            }
            default: break;
        }
    }
}