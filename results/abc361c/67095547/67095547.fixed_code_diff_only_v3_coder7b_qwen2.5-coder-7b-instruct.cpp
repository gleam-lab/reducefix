#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    // Sort the array to facilitate finding min/max differences
    sort(all(a));
    
    // Initialize variables to store the minimum difference found
    ll min_diff = LLONG_MAX;
    
    // Iterate over possible starting positions for the subarray
    for(int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum values in the current subarray
        ll diff = a[i + k - 1] - a[i];
        
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }
    
    // Print the result
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}