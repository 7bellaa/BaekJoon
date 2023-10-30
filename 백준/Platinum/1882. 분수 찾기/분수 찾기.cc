#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int count_less(int a, int n) {
    vector<int> cnt(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cnt[i] = min(i - 1, i * a / n);
    }

    int result = 0;
    for (int i = 2; i <= n; i++) {
        result += cnt[i];
        for (int j = 2 * i; j <= n; j += i) cnt[j] -= cnt[i];
    }

    return result;
}

int main() {
    int n, k; cin >> n >> k;

    int up = 0;
    for (int p = 29; p >= 0; p--) {
        if ((1 << p) + up > n) continue;
        if (count_less((1 << p) + up, n) < k) up += (1 << p);
    }
    k -= count_less(up, n);

    vector<pair<int, int>> elements;
    for (int i = 1; i <= n; i++) {
        int b = i;
        int a = (up + 1) * b / n;
        if (up * b >= a * n) continue;
        if (a * n > (up + 1) * b) continue;
        if (gcd(a, b) != 1) continue;

        elements.push_back({a, b});
    }

    sort(elements.begin(), elements.end(), [] (const pair<int, int>& lhs, const pair<int, int>& rhs) {return lhs.first * rhs.second < rhs.first * lhs.second;});
    cout << elements[k - 1].first << ' ' << elements[k - 1].second;
}