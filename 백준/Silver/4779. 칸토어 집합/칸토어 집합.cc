#include <bits/stdc++.h>
using namespace std;

vector<string> dp(13, "\0");

string cantor(const int &n) {
    if (dp[n] != "\0") return dp[n];
    string tmp1 = cantor(n-1), tmp2 = "";
    for (int i = 0; i < tmp1.length(); i++) tmp2 += " ";
    return dp[n] = tmp1 + tmp2 + tmp1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    dp[0] = "-";
    while (cin >> n) cout << cantor(n) << '\n';
}