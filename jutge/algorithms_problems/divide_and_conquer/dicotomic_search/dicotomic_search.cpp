/*
Write an efficient function

bool resistant_search(double x, const vector<double>& v);
that tells if x belongs to the vector v or not.

Precondition

The vector v is “almost sorted” in nondecreasing order, in the sense that there may be at most a pair of indices i and j such that 0 ≤ i < j < n and V[i] > V[j].

Observation You only need to submit the required procedure; your main program will be ignored.
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> V;

bool resistant_search_i(const vector<double>& v, double x, int left, int right) {
    if (left >= right) {
        return false;
    } else {
        int median = (left + right) / 2;
        if (x == v[median]) return true;
        else if (median - 1 >= 0 and v[median - 1] == x) return true;
        else if (median + 1 < v.size() and v[median + 1] == x) return true;
        else if (x < v[median]) return resistant_search_i(v, x, left, median);
        else return resistant_search_i(v, x, median + 1, right);
    }
}

bool resistant_search(double x, const vector<double>& v) {
    return resistant_search_i(v, x, 0, v.size());
}

int main() {
    int n; 
    cin >> n;
    V v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    double x = 2;
    if (resistant_search(x, v)) cout << "resistencia encontrada" << endl;
    else cout << "BUUUH" << endl;
}
