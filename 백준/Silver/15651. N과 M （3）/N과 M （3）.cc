#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;

void solve(int x) {
    if (x == M) {
        for (auto i : nums) cout << i << ' ';
        cout << '\n';
        return ;
    }

    for (int i = 1; i <= N; i++) {
        nums.push_back(i);
        solve(x+1);
        nums.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    solve(0);
}