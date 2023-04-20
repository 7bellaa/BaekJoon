#include <bits/stdc++.h>
using namespace std;

int N, K, ans;

void merge (int (&A)[], int p, int q, int r) {
    static int cnt = 0;
    int i = p, j = q+1, t = 0;
    int tmp[r-p+1];

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];
    i = p; t = 0;
    while (i <= r) {
        cnt++;
        A[i++] = tmp[t++];
        if (cnt == K) ans = A[i-1];
    }
}

void merge_sort(int (&A)[], int p, int r) {
    if (p < r) {
        int q = (p+r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    int arr[N];
    for (auto &i : arr) cin >> i;

    merge_sort(reinterpret_cast<int (&)[]>(arr), 0, N - 1);
    if (ans) cout << ans;
    else cout << -1;
}