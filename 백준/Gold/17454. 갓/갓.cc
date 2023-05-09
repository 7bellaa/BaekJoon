#include <bits/stdc++.h>
using namespace std;

bool isCheck() {
    int DH, DS, HD, HS, SD, SH;
    cin >> DH >> DS >> HD >> HS >> SD >> SH;

    if (HD >= HS || SD >= SH) return true;
    if (HD * SD > (HS-HD) * (SH-SD)) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        if (isCheck()) cout << "GOD\n";
        else cout << "KDH\n";
    }
}