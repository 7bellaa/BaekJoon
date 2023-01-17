#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(void) {
    deque<int> q;
    int n, m, ans = 0;
    cin >> n >> m;
    while (n--) q.push_front(n+1);

    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];

    for (auto i : a) {
        int cnt = 0;
        while (q.front() != i) {
            cnt++;
            int t = q.front();
            q.pop_front();
            q.push_back(t);
        }
        ans += min(cnt, (int)q.size()-cnt);
        q.pop_front();
    }
    cout << ans;
    return 0;
}