#include <iostream>
using namespace std;

int main(void) {
    int a, idx = 0, mx = 1;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        if (a > mx) {
            idx = i;
            mx = a;
        }
    }
    cout << mx << '\n' << idx+1;
    return 0;
}