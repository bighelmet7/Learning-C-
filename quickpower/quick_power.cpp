#include <iostream>
using namespace std;

int quick_power(int x, int n) {
    if (n == 0) return 1;
    else {
        int y = quick_power(x, n / 2);
        if (n % 2 == 0) return y * y;
        else            return x * y * y;
    }
}

int main() {
    //x^n
    int x = 2, n = 5;
    cout << quick_power(x, n) << endl;
}