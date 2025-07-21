#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find min and max values after removal
    sort(a.begin(), a.end());

    // Initialize variables to store the minimum difference found
    int min_diff = INT_MAX;

    // Iterate over possible positions to remove k elements
    for(int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the max and min values in the remaining subarray
        int diff = a[i + k - 1] - a[i];
        // Update the minimum difference if the current one is smaller
        min_diff = min(min_diff, diff);
    }

    // Output the result
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}