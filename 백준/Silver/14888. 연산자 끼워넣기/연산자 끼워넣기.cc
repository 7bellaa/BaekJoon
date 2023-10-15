#include <bits/stdc++.h>
using namespace std;

int N, T, minValue = numeric_limits<int>::max(), maxValue = numeric_limits<int>::min();
vector<int> nums;
char op[4] = {'+', '-', '*', '/'};
map<char, int> opCnt;

int calculate(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return a;
    }
}

void solve(int idx, int res) {
    if (idx == N) {
        minValue = min(res, minValue);
        maxValue = max(res, maxValue);
        return;
    }

    for (auto c : op) {
        if (opCnt[c] > 0) {
            opCnt[c]--;
            solve(idx+1, calculate(c, res, nums[idx]));
            opCnt[c]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T;
        nums.push_back(T);
    }
    for (auto c : op) {
        cin >> T;
        opCnt[c] = T;
    }
    solve(1, nums[0]);
    cout << maxValue << '\n' << minValue;
}