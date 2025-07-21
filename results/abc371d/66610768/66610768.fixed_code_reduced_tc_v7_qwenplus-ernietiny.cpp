#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n; // Number of elements in array a
    vector<int> a(n + 1); // Preallocate space for array a
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read elements from array a
    }
    vector<int> c(n + 2); // To store intermediate results
    for (int i = 1; i <= n; ++i) {
        c[i] = a[i] + c[i - 1]; // Compute c[i] by adding previous element
    }
    // Reading and processing input correctly, handle case when range is narrower than elements in array
    while (m--) {
        int l, r;
        cin >> l >> r; // Read ranges from user
        // Check if the range is wider than elements in array to avoid boundary issues
        if (r < a[n]) {
            cout << c[n] - c[n - l] << endl; // Output result if range is narrower than elements in array
        } else {
            // Calculate and output the intermediate result based on range boundaries
            auto l_i = lower_bound(a.begin() + 1, a.end(), l); // Find index of lower element in array
            auto r_j = upper_bound(c.begin(), c.end(), r); // Find index of the current element's range upper bound
            int i = l_i - a.begin(); // Calculate the index of current element in the range
            int j = r_j - c.begin(); // Calculate the index of the current element's range upper bound minus one (to skip the first element)
            cout << c[j - 1] - c[i - 1] << endl; // Output the intermediate result based on the actual range boundaries
        }
    }
    return 0;
}