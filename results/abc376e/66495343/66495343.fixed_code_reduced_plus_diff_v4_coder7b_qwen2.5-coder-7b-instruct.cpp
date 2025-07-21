#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    // Sort arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Calculate initial sum of B
    ll sum_b = accumulate(b.begin(), b.begin() + k, 0LL);
    
    // Initialize result with the maximum possible value
    ll res = LLONG_MAX;
    
    // Iterate through A using sliding window
    for (int i = 0; i <= n - k; ++i) {
        // Calculate current product
        ll curr_product = a[i] * sum_b;
        
        // Update result if current product is smaller
        res = min(res, curr_product);
        
        // Update sum_b for the next iteration
        if (i > 0) {
            sum_b += b[i + k - 1] - b[i - 1];
        }
    }
    
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}