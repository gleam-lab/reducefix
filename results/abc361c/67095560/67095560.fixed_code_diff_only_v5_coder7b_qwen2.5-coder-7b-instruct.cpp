#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define vi vector<ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    // The optimal strategy is to remove the smallest k/2 elements and the largest k/2 elements
    // This way, the difference between the max and min values of the resulting array is minimized
    ll ans = a[k - 1] - a[0]; // If k is odd, we only remove one more element from the larger half
    if (k % 2 == 0) {
        ans = min(ans, a[k] - a[1]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}