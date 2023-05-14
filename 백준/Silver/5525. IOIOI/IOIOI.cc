#include <bits/stdc++.h>
using namespace std;

string s;
int n, m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s;

    int start = 0, end = 1, cnt = 0;
    while (start < m-1 && end < m) {
        if (s[start] == 'O') {start++; end++; continue;}

        while (end < m) {
            if (s[end] != s[end-1]) {
                if (end-start == 2*n) {
                    start += 2;
                    end++;
                    cnt++;
                    break;
                }
                end++;
            }
            else {
                start = end;
                end = start + 1;
                break;
            }
        }
    }
    cout << cnt;
}