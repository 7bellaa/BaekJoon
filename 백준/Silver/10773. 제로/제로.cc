#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector<int> a;
    while (n--) {
        int x; cin >> x;
        if (x) a.push_back(x);
        else a.pop_back();
    }
    int ans = 0;
    for (auto i : a) ans += i;
    cout << ans;
    return 0;
}