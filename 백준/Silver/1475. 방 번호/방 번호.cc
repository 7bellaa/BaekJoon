#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, cnt[10] = {0};
    cin >> n;
    while (n) {
        cnt[n%10]++;
        n /= 10;
    }
    cnt[6] = (cnt[6]+cnt[9]+1)/2;
    cnt[9] = 0;
    cout << *max_element(cnt, cnt+10);
    return 0;
}