#include <iostream>
#include <vector>
using namespace std;

int max_position(const vector<int>& v, int m) {
    int k = 0;
    for (int i = 0; i <= m; ++i)
        if (v[i] > v[k]) k = i;
    return k;
}

void selection_sort(vector<int>& v, int n) {
    for (int i = n - 1; i >= 0; --i) {
        int max_pos = max_position(v, i);
        swap(v[max_pos], v[i]);
    }
}

int main() {
    int n = 4;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    selection_sort(v, n); //n = v.size()
    //Time complexity of Theta(n^2)
    for (int i = 0; i < n; ++i) cout << v[i] << ' ';
    cout << endl;
}