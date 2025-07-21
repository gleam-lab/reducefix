#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Sort the array to easily find the min and max after removing K elements
    sort(a.begin(), a.end());

    // The optimal way to minimize the difference between max and min values of the new sequence B
    // is to always remove the smallest or largest element in each step.
    // Since we want to minimize the difference, we should aim to keep the smallest elements as small
    // as possible and the largest elements as large as possible after removal.
    
    int ans = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        // Calculate the difference between the max and min values of the remaining elements
        ans = min(ans, a[min(k, n - 1)] - a[max(0, n - k - 1)]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}