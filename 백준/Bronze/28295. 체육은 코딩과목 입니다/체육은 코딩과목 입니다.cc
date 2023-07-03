#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int sum = 0, n;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        sum = (sum + n) % 4;
    }
    string dir = "NESW";
    cout << dir[sum];
}