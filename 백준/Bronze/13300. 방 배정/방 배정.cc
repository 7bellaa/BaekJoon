#include <iostream>
using namespace std;

int main(void) {
    int n, k, x, y, a[6][2] = {};
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a[y-1][x]++;
    }
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        cnt += (a[i][0]+1) / 2;
        cnt += (a[i][1]+1) / 2;
    }
    cout << cnt;
    return 0;
}