#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a[26] = {0};
    string s;
    getline(cin, s);
    for (char c : s) a[c-'a']++;
    for (int i : a) cout << i << ' ';
    return 0;
}