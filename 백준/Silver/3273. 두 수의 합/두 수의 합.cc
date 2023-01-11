#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, x, cnt=0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    sort(a, a+n);
    int i=0, j=n-1;
    while (i < j) {
        int t = a[i] + a[j];
        if (t > x) j--;
        else if (t < x) i++;
        else {cnt++; i++; j--;}
    }
    cout << cnt;
    return 0;
}