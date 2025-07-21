#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n); // Corrected size of s vector
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i > 0) s[i] = s[i - 1] + p[i]; // Accumulate partial sums
    }
    // No need for a separate s[n+1] as it was not used properly before
    
    int q;
    cin >> q;
    while (q--) { // Process each query
        int l, r;
        cin >> l >> r; // Read l and r for each query
        // Adjusting for one-based indexing as per upper_bound/lower_bound results
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin() - 1; // Decrement for zero-based array indexing in s
        // Assuming we want to find a value related to the range [lt, rt] in s (depending on actual logic)
        ll ans = (rt > 0) ? s[rt] - s[lt] : 0; // Handle edge cases where rt is 0 (out of bounds)
        cout << ans << endl; // Output the result for this query
    }
    return 0;
}