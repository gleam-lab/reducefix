#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    // Sort the array to easily find the min and max values after removal
    sort(a.begin(), a.end());

    // The optimal strategy is to remove the smallest K elements to minimize the difference between max and min
    ll result = a[n-1] - a[k];

    // Additionally, consider removing the largest K elements to further minimize the difference
    result = min(result, a[n-k-1] - a[0]);

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}