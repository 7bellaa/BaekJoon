#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        int c[26] = {};
        for (char i : a) c[i-'a']++;
        for (char i : b) c[i-'a']--;

        bool flag = true;
        for (int i : c) {
            if (i) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }
    return 0;
}