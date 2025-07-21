#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    // Sort the array x since we'll be using binary search later.
    sort(x.begin(), x.end());
    vector<ll> p(n + 1, 0); // Initialize p with 0 to avoid uninitialized values in prefix sum calculation
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + x[i - 1]; // Calculate prefix sum of x
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; // Read the query range [l, r]
        // Use binary search to find the indices of l and r in the sorted array x
        auto it_l = lower_bound(x.begin(), x.end(), l);
        auto it_r = upper_bound(x.begin(), x.end(), r);
        // Adjust the indices since binary search might place the iterator one position before the actual element
        int idx_l = it_l - x.begin();
        int idx_r = (it_r - x.begin()) - 1; // Subtract 1 because upper_bound returns one position after the last element <= r
        // Calculate the answer using prefix sum array p
        ll ans = p[idx_r + 1] - p[idx_l]; // Subtracting p[idx_l] because we want [l, r) range instead of [l, r]
        cout << ans << endl; // Output the answer for each query
    }
    return 0;
}