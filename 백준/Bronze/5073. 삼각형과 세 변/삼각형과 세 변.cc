#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c && a+b+c) {
        int arr[3] = {a, b, c};
        sort(arr, arr+3);
        if (arr[0] + arr[1] <= arr[2]) cout << "Invalid\n";
        else if (arr[0] == arr[2]) cout << "Equilateral\n";
        else if (arr[0] == arr[1] || arr[1] == arr[2]) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}