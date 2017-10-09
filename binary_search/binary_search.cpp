#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V;

int binary_search(const vector<int>& v, int x, int left, int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if (x < v[middle]) return binary_search(v, x, left, middle - 1);
        else if (x > v[middle]) return binary_search(v, x, middle + 1, right);
        else return middle;
    } 
    else return -1;
}

int main() {
    V v(10);
    int j = 1;
    for (int i = 0; i < 10; ++i) {
        v[i] = j;
        ++j;
    }
    int x = 3;
    int position = binary_search(v, x, 0, v.size() - 1);
    if (position != -1)
        cout << "Found it in position: " << position << endl;
    else
        cout << "Doesnt exists" << endl;
}