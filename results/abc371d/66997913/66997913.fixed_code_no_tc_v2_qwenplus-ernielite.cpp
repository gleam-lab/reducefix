#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n); // Corrected variable name from 'p' to 'x' to match the intended usage.
    for (int i = 0; i < n; i++) cin >> x[i]; // Read the elements of the sequence x.

    // Instead of maintaining two separate arrays for p and s, we can calculate the sum of prefixes in-place.
    vector<ll> prefixSum(n + 1, 0); // Create a vector to store the prefix sums.
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + x[i]; // Calculate the prefix sum in-place.
    }
    
    // Now we can perform the range sum queries efficiently using the prefixSum array.
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; // Read the left and right indices of the range query.
        // The indices need to be zero-based for lower_bound and upper_bound to work correctly.
        l--; r--; // Adjusting indices for lower_bound and upper_bound.
        // We can now use lower_bound and upper_bound to find the indices in x that are greater or equal to l and r respectively.
        auto itL = lower_bound(x.begin(), x.end(), l); // This is equivalent to finding lt in your original code.
        auto itR = upper_bound(x.begin(), x.end(), r); // This is equivalent to finding rt in your original code.
        // The actual range sum query is now between the two indices found by lower_bound and upper_bound.
        int ans = prefixSum[itR - x.begin()] - prefixSum[itL - x.begin() - 1]; // Subtracting 1 from itL because we need to exclude the left index from the sum.
        cout << ans << endl; // Output the result of the range sum query.
    }
    return 0;
}