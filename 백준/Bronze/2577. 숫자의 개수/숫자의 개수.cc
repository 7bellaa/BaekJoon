#include <iostream>
using namespace std;

int main(void) {
    int a,b,c, cnt[10] = {0};
    cin >> a >> b >> c;
    a *= b*c;
    while (a) {
        cnt[a%10]++;
        a /= 10;
    }
    for (auto i : cnt) cout << i << '\n';
    return 0;
}