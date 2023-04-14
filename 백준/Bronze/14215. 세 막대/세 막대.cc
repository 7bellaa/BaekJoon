#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, arr+3);
    if (arr[0] + arr[1] <= arr[2]) cout << 2 * (arr[0] + arr[1]) - 1;
    else cout << arr[0] + arr[1] + arr[2];
}