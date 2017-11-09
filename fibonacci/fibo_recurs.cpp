//Classic recursive fibonacci sequence
#include<iostream>
using namespace std;

int fibo_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo_rec(n - 1) + fibo_rec(n - 2);
}

int main() {
    int n = 10;
    cout << fibo_rec(n) << endl;
}