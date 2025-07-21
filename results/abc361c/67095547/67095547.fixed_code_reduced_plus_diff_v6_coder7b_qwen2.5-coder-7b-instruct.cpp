#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // We need to minimize the difference between the max and min values in the resulting array
    // If we remove k elements, we can either remove from the start or end to get the minimum difference
    // The best strategy is to remove the smallest k/2 elements from the start and largest k/2 elements from the end
    // This way, the difference between the max and min values will be minimized

    ll ans = LLONG_MAX;
    for(int i = 0; i <= k; ++i) {
        // Remove i elements from the start and (k-i) elements from the end
        ll diff = a[k - i] - a[i];
        ans = min(ans, diff);
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while(t--) {
        solve();
    }

    return 0;
}