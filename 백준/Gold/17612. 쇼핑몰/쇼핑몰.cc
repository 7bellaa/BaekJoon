#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Person {
    ll id;
    int time, cntNum;
};

int N, K;
vector<pair<ll, int>> customer;

struct cmp {
    bool operator () (const Person& a, const Person& b) {
        if (a.time == b.time) return a.cntNum < b.cntNum;
        return a.time > b.time;
    }
};

void init() {
    cin >> N >> K;
    if (K > N) K = N;
    for (int i = 0; i < N; i++) {
        int id, w; cin >> id >> w;
        customer.push_back({id, w});
    }
}

void solve() {
    ll ans = 0;

    priority_queue<Person, vector<Person>, cmp> pq;
    for (int i = 0; i < K; i++) {
        auto [id, w] = customer[i];
        pq.push({id, w, i});
    }

    int idx = K, cnt = 0;
    while (cnt < N) {
        vector<Person> outs;
        auto out = pq.top();
        while (!pq.empty() && out.time == pq.top().time) {
            outs.push_back(pq.top()); pq.pop();
        }

        for (auto &p: outs)
            ans += (++cnt) * p.id;

        for (auto it = outs.rbegin(); it != outs.rend() && idx < N; it++, idx++)
            pq.push({customer[idx].first, customer[idx].second + out.time, it->cntNum});
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
}