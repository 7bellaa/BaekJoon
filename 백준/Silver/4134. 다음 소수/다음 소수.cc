#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long &n) {
    if(n <= 1) return false;
    if (n <= 3)  return true; 
    
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    
    for (long long i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    
    return true;
}

long long solve() {
    long long n; cin >> n;
    while (1) {
        if (isPrime(n)) return n;
        n++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while (N--) {
        cout << solve() << '\n';
    }
}