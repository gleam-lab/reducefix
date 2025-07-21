#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll i=0; i<n; ++i) cin >> a[i];
    for(ll i=0; i<n; ++i) cin >> b[i];

    vector<pair<ll, ll>> pairs(n);
    for(ll i=0; i<n; ++i) pairs[i] = {a[i], b[i]};
    sort(pairs.begin(), pairs.end());

    vector<ll> prefix_sum(n+1);
    for(ll i=1; i<=n; ++i) prefix_sum[i] = prefix_sum[i-1] + pairs[i-1].second;

    ll res = LLONG_MAX;
    for(ll i=k-1; i<n; ++i) {
        ll max_a = pairs[i].first;
        ll sum_b = prefix_sum[i+1] - prefix_sum[i-k+1];
        res = min(res, max_a * sum_b);
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}