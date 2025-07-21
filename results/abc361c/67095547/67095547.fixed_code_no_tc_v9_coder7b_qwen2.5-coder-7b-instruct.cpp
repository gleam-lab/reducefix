#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define mp make_pair

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Sort the array to easily find the minimum and maximum values after removal
    sort(a.begin(), a.end());

    // Initialize the result with the difference between the largest and smallest elements
    ll result = a[n - 1] - a[0];

    // Iterate through each possible position to remove k elements
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the new difference after removing k elements
        ll current_result = a[min(n - 1, i + k - 1)] - a[max(0, i - 1)];
        // Update the result with the minimum difference found
        result = min(result, current_result);
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}