#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V;

void merge(vector<int>& v, int left, int median, int right) {
    //right - left = v.size() - 1, so to get the size of v, just sum 1
    vector<int> Aux(right - left + 1);
    int i = left, j = median + 1, k = 0; //k defines the index of Aux.
    while (i <= median and j <= right) {
        //Its sorted so we just add v[i] to Aux and update the index's.
        if (v[i] <= v[j]) Aux[k++] = v[i++];
        else              Aux[k++] = v[j++]; //Otherwise
    }
    //Add the remainders elements to Aux
    while (i <= median) Aux[k++] = v[i++];
    while (j <= right ) Aux[k++] = v[j++];

    //Update the v vector with the sorted vector Aux
    //left its always the leftmost index in v.
    for (k = 0; k <= right - left; ++k) v[left + k] = Aux[k];
}

void imergesort(vector<int>& v, int left, int right) {
    if (left < right) {
        int median = (left + right) / 2;
        imergesort(v, left, median);
        imergesort(v, median + 1, right);
        merge(v, left, median, right);
    }
}

// Has a time complexity of Theta(n log n)
void mergesort(vector<int>& v) {
    imergesort(v, 0, v.size() - 1);
}

int main() {
    int n = 10;
    V v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    mergesort(v);
    for (int i = 0; i < n; ++i) {
        if (i == 0) cout << v[i];
        else        cout << " " << v[i];
    }
    cout << endl;
}