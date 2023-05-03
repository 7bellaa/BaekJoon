#include <bits/stdc++.h>
using namespace std;

string s;

bool isSlump(int idx, const int& slumpSize) {
    if (s[idx] != 'D' && s[idx] != 'E') return false;
    else idx++;
    if (s[idx] != 'F') return false;

    while (s[idx] == 'F') idx++;
    if (idx == slumpSize-1) {
        if (s[idx] == 'G') return true;
        else return false;
    }
    else return isSlump(idx, slumpSize);
}

bool isSlimp(int idx, const int& slimpSize) {
    if (s[idx] != 'A') return false;
    else idx++;
    if (idx + 1 == slimpSize) {
        if (s[idx] == 'H') return true;
        else return false;
    }
    else if (slimpSize > 2) {
        if (s[idx] == 'B') {
            if (isSlimp(idx+1, slimpSize-1)) return true;
            else return false;
        } else {
            if (isSlump(idx, slimpSize-1)) return true;
            else return false;
        }
    }
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cout << "SLURPYS OUTPUT\n";
    while (n--) {
        s.clear();
        cin >> s;
        int tmp = 0;
        if (s[1] == 'H') tmp = 2;
        else {
            while (s[tmp] != 'C') tmp++;
            while (s[tmp] == 'C') tmp++;
        }

        if (isSlimp(0, tmp) && isSlump(tmp, s.size())) cout << "YES\n";
        else cout << "NO\n";
    }
    cout << "END OF OUTPUT";
}