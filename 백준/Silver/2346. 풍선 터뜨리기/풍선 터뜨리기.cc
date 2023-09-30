#include <bits/stdc++.h>
using namespace std;

vector<int> v(1, 0);
deque<int> dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    for (int i = 1; i <= N; i++) dq.push_back(i);

    while (!dq.empty()) {
        int balloon = dq.front(); dq.pop_front();
        cout << balloon << ' ';
        if (v[balloon] > 0) v[balloon]--;

        while (v[balloon] != 0 && !dq.empty()) {
            if (v[balloon] > 0) {
                v[balloon]--;
                int t = dq.front(); dq.pop_front();
                dq.push_back(t);
            }
            else {
                v[balloon]++;
                int t = dq.back(); dq.pop_back();
                dq.push_front(t);
            }
        }
    }
}