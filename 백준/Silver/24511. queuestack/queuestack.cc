#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> queuestack;
    deque<int> elements;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        queuestack.push_back(t);
    }
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        if (queuestack[i] == 0) elements.push_back(t);
    }

    int M; cin >> M;
    while (M--) {
        int x; cin >> x;
        elements.push_front(x);
        cout << elements.back() << ' ';
        elements.pop_back();
    }
}