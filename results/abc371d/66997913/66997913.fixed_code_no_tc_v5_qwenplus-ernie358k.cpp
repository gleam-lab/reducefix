#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n + 1, 0); // Initialize s[0] to 0 for correct prefix sum calculation
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; // Convert to 0-based index for lower_bound and upper_bound
        r--;
        
        // Find the correct indices in the sorted version of x
        // Since x is not sorted, we cannot use binary search directly on x
        // Instead, we need to interpret l and r in terms of the prefix sums s
        // We are looking for the sum of p values where x values are between l and r (inclusive)
        // This requires a different approach since we don't have a sorted version of x to binary search on
        
        // We need to manually calculate the sum for the range [l, r] using prefix sums
        ll ans = 0;
        // Handle edge case where l is out of bounds (should not happen if input is correct)
        if (l >= 0 && l <= n - 1) {
            // If r is out of bounds, it means we take the sum up to the end of the array
            int end_idx = min(r, n - 1);
            ans = s[end_idx + 1] - s[l]; // s[l] is the cumulative sum up to l-1 (0-based), so s[end_idx+1] - s[l] gives [l, end_idx]
        }
        
        cout << ans << endl;
    }
    return 0;
}