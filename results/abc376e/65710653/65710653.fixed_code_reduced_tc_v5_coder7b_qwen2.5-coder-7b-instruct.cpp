#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

void solve() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    
    // Sort arrays based on A and B values
    vector<pll> ab(n);
    rep(i, n) ab[i] = {a[i], b[i]};
    sort(ab.begin(), ab.end());
    
    // Initialize variables for sliding window
    ll sum_b = 0;
    rep(i, k) sum_b += ab[i].second;
    
    ll ans = sum_b * ab[k - 1].first;
    rep(i, n - k) {
        sum_b += ab[i + k].second - ab[i].second;
        ans = min(ans, sum_b * ab[i + k].first);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}