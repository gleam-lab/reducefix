#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    // Sort the array to facilitate finding the minimum difference after removal
    sort(a.begin(), a.end());
    
    // Initialize the result with the maximum possible difference
    int result = a[n-1] - a[0];
    
    // Iterate through all possible pairs of indices where one index is at most k positions before the other
    for(int i = 0; i <= n-k; ++i) {
        // Calculate the potential result by removing elements outside the current window of size n-k
        int potential_result = a[i+k-1] - a[i];
        // Update the result if the potential result is smaller
        result = min(result, potential_result);
    }
    
    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}