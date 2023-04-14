#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 0;
    while (cin >> N && N != -1) {
        int arr[N];
        fill(arr, arr+N, 0);
        arr[1] = 1;
        for (int i = 2; i < N/2; i++) {
            if (N % i == 0) {
                arr[i] = 1;
                arr[N/i] = 1;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i]) sum += i;
        }

        if (sum == N) {
            cout << N << " = 1";
            for (int i = 2; i < N; i++)
                if (arr[i]) cout << " + " << i;
            cout << '\n';
        } else {
            cout << N << " is NOT perfect.\n";
        }
    }
}