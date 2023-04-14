#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2;
    int N; cin >> N;
    while (N--) {
        int a, b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    auto [x1, x2] = minmax_element(v1.begin(), v1.end());
    auto [y1, y2] = minmax_element(v2.begin(), v2.end());
    cout << (*x2-*x1) * (*y2-*y1);
}