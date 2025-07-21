#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200050;
vector<int> a(MAX_N), b;

int main() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < q; ++j) {
        cin >> b[j] >> a[j];  // Note that a[j] is read here and stored in b[j]
    }
    sort(a.begin(), a.begin() + n);
    for (int j = 0; j < q; ++j) {
        int x = b[j];
        int k = a[j];  // Adjusted: k is now the j-th index for A
        int dist = a[k - 1] - x;  // We use k - 1 because the array is 0-indexed
        cout << (long long)dist * dist << endl;  // Output the square of the distance
    }
    return 0;
}