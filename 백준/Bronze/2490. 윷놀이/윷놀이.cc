#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int a,b,c,d;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b >> c >> d;
        switch (a+b+c+d)
        {
        case 0:
            cout << 'D' << '\n';
            break;
        case 1:
            cout << 'C' << '\n';
            break;
        case 2:
            cout << 'B' << '\n';
            break;
        case 3:
            cout << 'A' << '\n';
            break;
        case 4:
            cout << 'E' << '\n';
            break;
        default:
            break;
        }
    }
    return 0;
}