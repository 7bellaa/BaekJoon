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
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    a1 *= b2;
    a2 *= b2;
    b1 *= a2/b2;
    b2 = a2;

    a1 += b1;
    int c = gcd(a1, a2);
    cout << a1/c << ' ' << a2/c;
}