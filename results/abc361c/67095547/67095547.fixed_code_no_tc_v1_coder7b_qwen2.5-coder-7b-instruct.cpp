#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define vi vector<ll>
#define pb push_back
#define mp make_pair

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    
    // Sort the array to easily find min/max values after removing K elements
    sort(all(a));
    
    // Initialize the minimum difference with a large number
    ll ans = LLONG_MAX;
    
    // Iterate through possible positions to remove K elements
    rep(i, n-k+1) {
        // Calculate the difference between max and min values after removing K elements
        ll diff = a[i+k-1] - a[i];
        // Update the minimum difference found so far
        ans = min(ans, diff);
    }
    
    // Output the result
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}