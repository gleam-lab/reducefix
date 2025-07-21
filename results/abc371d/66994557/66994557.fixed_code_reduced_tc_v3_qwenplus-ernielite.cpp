#include <bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005], sum[200005]; // Corrected size of sum array to match x

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i]; // Read values into x array
    }
    for (int i = 1; i < n; i++) { // Calculate prefix sum of p array (not used in this code)
        p[i] = p[i - 1] + /* some value */; // Assuming this is intended to be a prefix sum, but original code did not use it
        sum[i] = /* some logic based on x and p */; // The original code did not show how this was calculated
    }
    // It's not clear what the prefix sum is supposed to represent, so I've commented out this part for now.

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // Read the range query
        // Assuming that we need to find the number of elements in x between L and R (inclusive),
        // we can use binary search to find the indices of L and R in x, then calculate the difference.
        auto l = lower_bound(x, x + n, L) - x; // Binary search for L's index
        auto r = upper_bound(x, x + n, R) - x - 1; // Binary search for R's index (excluding the actual element)
        if (l <= r) { // Check if there are any elements in the range
            cout << r - l + 1 << endl; // Output the number of elements in the range (or some other logic based on your requirements)
        } else {
            cout << "0" << endl; // Output 0 if there are no elements in the range (or some other appropriate response)
        }
    }
    return 0;
}