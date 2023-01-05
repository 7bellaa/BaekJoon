#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int a[9], sum = 0;
    for (int i = 0; i < 9; i++) cin >> a[i];
    sort(a, a+9);

    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (k != i && k != j) sum += a[k];
            }
            if (sum == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) cout << a[k] << '\n';
                }
                return 0;
            }
            sum = 0;
        }
    }
    return 0;
}