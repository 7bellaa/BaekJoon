#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    int n, ans = 0;
    cin >> n;
    while (n--) {
        stack<char> a;
        string s;
        cin >> s;

        for (auto i : s) {
            if (a.empty()) a.push(i);
            else if (i == a.top()) a.pop();
            else a.push(i);
        }
        if (a.empty()) ans++;
    }
    cout << ans;
    return 0;
}