#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MX = 1000007;
char dat[MX];
int pre[MX], nxt[MX];
int n, cur, unused = 1;
string s;

void insert(char c) {
    dat[unused] = c;
    pre[unused] = cur;
    nxt[unused] = nxt[cur];

    if (nxt[cur] != -1) pre[nxt[cur]] = unused;
    nxt[cur] = unused;
    cur = nxt[cur];
    unused++;
}

void erase(void) {
    if (pre[cur] != -1) {
        nxt[pre[cur]] = nxt[cur];
        if (nxt[cur] != -1) pre[nxt[cur]] = pre[cur];
        cur = pre[cur];
    }
}

void left(void) {
    if (pre[cur] != -1) cur = pre[cur];
}

void right(void) {
    if (nxt[cur] != -1) cur = nxt[cur];
}

void traverse(void) {
    int now = nxt[0];
    while (now != -1) {
        cout << dat[now];
        now = nxt[now];
    }
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    cin >> s;
    cin >> n;

    for (auto i : s) insert(i);

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == 'P') {
            char c;
            cin >> c;
            insert(c);
        } else {
            if (op == 'L') left();
            else if (op == 'D') right();
            else if (op == 'B') erase();
        }
    }

    traverse();
    return 0;
}