#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find the minimum and maximum values
    sort(a.begin(), a.end());

    // Initialize the result with a large number
    int result = INT_MAX;

    // Iterate through possible positions to remove k elements
    for(int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum values after removing k elements
        int diff = a[i + k - 1] - a[i];
        // Update the result with the minimum difference found
        result = min(result, diff);
    }

    // Print the final result
    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}