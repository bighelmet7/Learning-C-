#include <iostream>
#include <vector>
using namespace std;

//Time complexity of O(n^2)
//Worst case is a decrease vector [4,3,2,1]
void inserction_sort(vector<int>& v, int n) {
    for (int k = 1; k <= n - 1; ++k) {
        int t = k - 1;
        while (t >= 0 and v[t + 1] < v[t]) {
            swap(v[t], v[t + 1]);
            --t;
        }
    }
}

int main() {
    int n = 4;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    inserction_sort(v, n);
    for (int i = 0; i < n; ++i) cout << v[i] << ' ';
    cout << endl;
}