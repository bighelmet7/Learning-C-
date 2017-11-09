//Metaprogramming fibonacci sequences
#include <iostream>
using namespace std;

template<int N>
struct Fibo {
    static const unsigned long int value = Fibo<N - 1>::value + Fibo<N - 2>::value;
};

template<>
struct Fibo<0> {
    static const unsigned long int value = 0;
};

template<>
struct Fibo<1> {
    static const unsigned long int value = 1;
};

int main() {
    cout << Fibo<10>::value << endl;
}