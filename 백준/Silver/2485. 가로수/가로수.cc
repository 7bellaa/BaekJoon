#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
    int N; cin >> N;
    vector<int> v;
    int t; cin >> t;
    
    for (int i = 0; i < N-1; i++) {
        int t1; cin >> t1;
        v.push_back(t1-t);
        t = t1;
    }

    int a = v[0];
    for (auto i : v) a = gcd(a, i);
    cout << accumulate(v.begin(), v.end(), 0) / a - N+1;
}