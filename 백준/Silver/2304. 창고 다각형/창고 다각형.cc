#include <bits/stdc++.h>
using namespace std;
int N, L, H, ans, cmp, height[1001];

int main() {
    cin >> N;
    while (N--) {
        cin >> L >> H;
        height[L] = H;
    }
    
    int topIdx = distance(height, max_element(height, height+1001));
    for (int i = 0; i <= topIdx; i++) {
        cmp = max(cmp, height[i]);
        ans += cmp;
    }
    cmp = 0;
    for (int i = 1000; i > topIdx; i--) {
        cmp = max(cmp, height[i]);
        ans += cmp;
    }
    cout << ans;
}