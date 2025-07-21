#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    
    // Read sizes of toys and boxes
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // Sort the sizes of toys and boxes in descending order
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // Find the maximum size of toy that cannot fit in any of the existing boxes
    int maxToySizeThatCannotFit = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            maxToySizeThatCannotFit = a[i];
            break;
        }
    }

    // If we found a toy that cannot fit, we need to buy a box that can hold this toy
    if (maxToySizeThatCannotFit != 0) {
        cout << maxToySizeThatCannotFit << endl;
    } else {
        // Otherwise, the largest toy size will do
        cout << a[n - 1] << endl;
    }

    return 0;
}