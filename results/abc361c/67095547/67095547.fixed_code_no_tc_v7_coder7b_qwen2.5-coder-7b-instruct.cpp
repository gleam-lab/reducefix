#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    // Calculate the difference between the largest and smallest values after removing k elements
    int min_diff = INT_MAX;
    for(int i = 0; i <= k; ++i) {
        int diff = a[min(n - 1, i + k)] - a[max(0, i - 1)];
        min_diff = min(min_diff, diff);
    }

    cout << min_diff;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}