#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // Sort the toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize the minimum box size to be the size of the largest toy
    long long min_box_size = a[n - 1];

    // Iterate over each toy size
    for (int i = 0; i < n; ++i) {
        // If the current toy size is greater than the size of all existing boxes,
        // we need to consider purchasing a new box of larger size
        if (a[i] > b[i]) {
            // The new box size must be at least as large as the current toy size
            min_box_size = max(min_box_size, a[i]);
        }
    }

    // Output the minimum box size needed
    cout << min_box_size << endl;

    return 0;
}