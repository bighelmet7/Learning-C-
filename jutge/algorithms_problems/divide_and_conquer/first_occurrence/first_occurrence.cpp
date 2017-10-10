/*
Write an efficient function

int first_occurrence(double x, const vector<double>& v);
that returns the position of the first occurrence of x in the vector v. If x does not belong to v, return a -1.

Precondition

The vector v is sorted in nondecreasing order. (non-decreasing sequence, x(n+1) >= x(n))

Observation You only need to submit the required procedure; your main program will be ignored.
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> V;

int position(const vector<double>& v, double x, int left, int right) {
    if (left <= right) {
        int median = (left + right) / 2;
        if (x < v[median])  return position(v, x, left, median - 1);
        else if (x > v[median]) return position(v, x, median + 1, right);
        else {
            //Look for repeated
            if (median - 1 >= 0) {
                int position_repeated = position(v, x, left, median - 1);
                if (position_repeated != -1 ) return position_repeated;
            } 
            return median;
        }
    } 
    else {
        return -1;
    }
}

int first_occurrence(double x, const vector<double>& v) {
    return position(v, x, 0, v.size() - 1);
}

int main() {
    int n = 10;
    V v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    double x; //element we want to look for
    cin >> x;
    int position = first_occurrence(x, v); //complex time Theta(n log n) ??
    if (position != -1) cout << "Element x is in " << position << endl;
    else cout << "Element not found" << endl;

}