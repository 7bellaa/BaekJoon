#include <iostream>
#include <string>
using namespace std;

const int MX = 4000000;
int dat[MX], head, tail;

void push(int x){
    dat[tail++] = x;
}

void pop(){
    head++;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            push(x);
        }
        else if (s == "pop") {
            if (head == tail) cout << "-1\n";
            else {cout << front() << '\n'; pop();}
        }
        else if (s == "size") {
            cout << tail-head << '\n';
        }
        else if (s == "empty") {
            cout << !(tail-head) << '\n';
        }
        else if (s == "front") {
            if (head == tail) cout << "-1\n";
            else cout << front() << '\n';
        }
        else {
            if (head == tail) cout << "-1\n";
            else cout << back() << '\n';
        }
    }
    return 0;
}