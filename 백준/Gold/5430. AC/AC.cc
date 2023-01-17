#include <iostream>
#include <string>
#include <deque>
using namespace std;

void parse(string &s, deque<int> &q) {
    int num = 0;
    for (int i = 1; i < s.size()-1; i++) {
        if (s[i] == ',') {
            q.push_back(num);
            num = 0;
        }
        else {
            num = num*10 + s[i]-'0';
        }
    }
    if (num) q.push_back(num);
}

void print_result(deque<int> &q, int flag) {
    if (q.empty()) {
        cout << "[]\n";
        return;
    }
    cout << '[';
    if (flag) {
        for (int i = 0; i < q.size()-1; i++)
            cout << q[i] << ',';
        cout << q.back() << "]\n";
    }
    else {
        for (int i = q.size()-1; i > 0; i--)
            cout << q[i] << ',';
        cout << q.front() << "]\n";
    }
}

int main(void) {
    int t, n;
    string p, arr;
    cin >> t;
    while (t--) {
        deque<int> q;
        bool flag = true, flag2 = true;
        cin >> p >> n >> arr;
        parse(arr, q);

        for (auto i : p) {
            if (i == 'R')
                flag = !flag;
            else if (q.empty()) {
                cout << "error\n";
                flag2 = false;
                break;
            }
            else {
                if (flag) q.pop_front();
                else q.pop_back();
            }
        }
        if (flag2) print_result(q, flag);
    }
    return 0;
}