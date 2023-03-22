#include <bits/stdc++.h>
using namespace std;

int timetosec(string s) {
    int result = 0;
    result += stoi(s.substr(0,2)) * 3600;
    result += stoi(s.substr(3,2)) * 60;
    result += stoi(s.substr(6,2));
    return result;
}

void printtime(int sec) {
    int t = sec/3600;
    sec %= 3600;
    if (t < 10) cout << 0 << t <<':';
    else cout << t << ':';

    t = sec/60;
    sec %= 60;
    if (t < 10) cout << 0 << t <<':';
    else cout << t << ':';

    t = sec;
    if (t < 10) cout << 0 << t;
    else cout << t;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int a = timetosec(s1);
    int b = timetosec(s2);
    int t = b-a;
    if (t < 0) t += timetosec("24:00:00");
    printtime(t);
}