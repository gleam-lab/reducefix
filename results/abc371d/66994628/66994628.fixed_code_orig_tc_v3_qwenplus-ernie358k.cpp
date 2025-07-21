#include <bits/stdc++.h>
using namespace std;

int n, q;
long long x[200005], p[200005];
long long sum[200005]; // No need for a larger size, n+1 would suffice but we keep it as is for clarity

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { // Use 0-based indexing
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) { // Use 0-based indexing
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i]; // Calculate prefix sums correctly
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x, x + n, l); // It will return an iterator to the first element not less than l
        auto it_r = upper_bound(x, x + n, r); // It will return an iterator to the first element greater than r

        int idx_l = it_l - x; // Convert iterator to index
        int idx_r = it_r - x; // Convert iterator to index

        // Adjust idx_r since upper_bound gives the first position greater than r
        if (idx_r != n && x[idx_r] == r) {
            idx_r++; // Only increment if exactly r is found, to exclude it from the range (if needed based on problem requirements)
        } else {
            idx_r--; // Decrement to get the last valid index <= r
        }

        // Ensure indices are within bounds
        idx_l = max(0, idx_l);
        idx_r = min(n - 1, idx_r);

        // Print the sum of p values corresponding to the mapped indices in x
        cout << sum[idx_r + 1] - sum[idx_l] << endl; // Adjust for 0-based indexing in sum array
    }
    return 0;
}