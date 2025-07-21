#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005], prefixSum[200005]; // prefixSum for efficient sum calculation

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1); // Sort the array x

    // Calculate prefix sum of p array (including initial value 0)
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefixSum[i] = prefixSum[i - 1] + p[i]; // Calculate prefix sum of p
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; // Read l and r from input
        // Binary search to find the positions of l and r in sorted x array
        auto itL = lower_bound(x + 1, x + n + 1, l);
        auto itR = upper_bound(x + 1, x + n + 1, r);
        l = itL - x + 1; // Convert iterator to index (since we're using lower_bound) and adjust for zero-based indexing
        r = itR - x - 1; // Same for upper_bound but with an adjustment to handle past-the-end iterator (-1)
        // Calculate the sum using prefix sums (inclusive range)
        cout << prefixSum[r] - prefixSum[l - 1] << endl; // Output the result
    }
    return 0;
}