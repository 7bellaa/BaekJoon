#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int idx = 0, ans = 0;
    string s;
    cin >> s;
    stack<char> a;

    while (idx < s.size()) {
        if (s[idx] == '(') {
            if (s[idx+1] == ')') {
                ans += a.size();
                idx += 2;
            }
            else {
                a.push('(');
                idx++;
            }
        } else {
            a.pop();
            ans++;
            idx++;
        }
    }
    cout << ans;
    return 0;
}