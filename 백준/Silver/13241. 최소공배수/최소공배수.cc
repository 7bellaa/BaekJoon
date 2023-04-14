#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b);
}