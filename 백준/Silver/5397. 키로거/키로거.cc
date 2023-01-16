#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        list<char> a;
        auto cur = a.end();
        for (auto i : s) {
            if (i == '<') {
                if (cur != a.begin()) cur--;
            }
            else if (i == '>') {
                if (cur != a.end()) cur++;
            }
            else if (i == '-') {
                if (cur != a.begin()) {
                    cur--;
                    cur = a.erase(cur);
                }
            } else {
                a.insert(cur, i);
            }
        }
        for (auto c : a) cout << c;
        cout << '\n';
    }
    return 0;
}