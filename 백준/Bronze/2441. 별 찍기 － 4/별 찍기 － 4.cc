#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        int j = 0;
        for ( ; j < n-i; j++) cout << ' ';
        for ( ; j < n; j++) cout << '*';
        cout << '\n';
    }
    return 0;
}