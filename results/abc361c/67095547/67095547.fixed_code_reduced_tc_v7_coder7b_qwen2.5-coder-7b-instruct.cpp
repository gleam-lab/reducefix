#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = LLONG_MAX;
    for(int i = 0; i <= n-k; ++i) {
        ans = min(ans, a[i+k-1] - a[i]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}