#include <iostream>

using namespace std;
int l, r, k;

int f2() {
    if (l < 3) l = 3;
    if (r < l) return 0;
    return r-l+1;
}

int f3() {
    if (l < 6) l = 6;
    if (r < l) return 0;
    int res = (r/3) - (l/3);
    return l%3 ? res : res+1;
}

int f4() {
    if (l < 10) l = 10;
    if (r < l) return 0;
    int res = (r/2) - (l/2);
    if (l <= 12 && 12 <= r) return l%2 ? res-1 : res;
    return l%2 ? res : res+1;
}

int f5() {
    if (l < 15) l = 15;
    if (r < l) return 0;
    int res = (r/5) - (l/5);
    return l%5 ? res : res+1;
}

int main() {
    cin >> l >> r >> k;
    switch (k) {
        case 2:
            cout << f2();
            break;

        case 3:
            cout << f3();
            break;
        
        case 4:
            cout << f4();
            break;

        case 5:
            cout << f5();
            break;
    }
}