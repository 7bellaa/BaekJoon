#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1000001;
int nums[N_MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(nums+2, nums+N_MAX, 1);
    for (int i = 2; i <= N_MAX/2; i++) {
        for (int j = i*2; j < N_MAX; j += i) {
            nums[j] += i;
        }
    }

    int start, stop, badness, cnt = 0;
    while (cin >> start >> stop >> badness && start) {
        int ans = 0;
        for (; start <= stop; start++) {
            if (abs(nums[start] - start) <= badness) ans++;
        }
        cout << "Test " << ++cnt << ": " << ans << '\n';
    }
}