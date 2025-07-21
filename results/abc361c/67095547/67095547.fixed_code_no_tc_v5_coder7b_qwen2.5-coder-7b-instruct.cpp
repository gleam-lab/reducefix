#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mod 1e9+7

typedef long long ll;

void solve(){
    int k, n;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    // Sort the array to facilitate finding the optimal subarray
    sort(all(a));
    
    // Initialize variables to store the minimum difference
    ll min_diff = LLONG_MAX;
    
    // Iterate over all possible starting positions for the subarray
    for(int i = 0; i <= n-k; ++i){
        // Calculate the difference between the maximum and minimum values in the current subarray
        ll diff = a[i+k-1] - a[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }
    
    // Output the result
    cout << min_diff;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}