#include <iostream>
#include <list>

using namespace std;

int main(void) {
    int n, k;
    list<int> a;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) a.push_back(i);

    auto it = a.begin();
    cout << '<';
    while (!a.empty()) {
        for (int i = 0; i < k-1; i++) {
            it++;
            if (it == a.end()) it = a.begin();
        }
        cout << *it;
        if (a.size() > 1) cout << ", ";
        it = a.erase(it);
        if (it == a.end()) it = a.begin();
    }
    cout << '>';
    return 0;
}