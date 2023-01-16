#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, i = 1;
    string ans;
    cin >> n;

    stack<int> a;
    a.push(0);
    while (n--) {
        int x; cin >> x;
        if (x == a.top()) {
            ans += "-\n";
            a.pop();
        }
        else if (x > a.top()) {
            for ( ; i <= x; i++) {
                a.push(i);
                ans += "+\n";
            }
            a.pop();
            ans += "-\n";
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << ans;
    return 0;
}