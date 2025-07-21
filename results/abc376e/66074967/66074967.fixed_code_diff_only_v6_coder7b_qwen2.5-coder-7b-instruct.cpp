#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll solve(ll n, ll k, vector<ll>& a, vector<ll>& b) {
    vector<pair<ll, ll>> pairs(n);
    for (ll i = 0; i < n; ++i) pairs[i] = {a[i], b[i]};
    sort(pairs.begin(), pairs.end());
    
    vector<ll> prefix_sum(n + 1);
    for (ll i = 1; i <= n; ++i) prefix_sum[i] = prefix_sum[i - 1] + pairs[i - 1].second;
    
    ll ans = LLONG_MAX;
    for (ll i = k - 1; i < n; ++i) {
        ll max_a = pairs[i].first;
        ll sum_b = prefix_sum[n] - prefix_sum[i];
        ans = min(ans, max_a * sum_b);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (auto &ai : a) cin >> ai;
        for (auto &bi : b) cin >> bi;
        
        cout << solve(n, k, a, b) << '\n';
    }
    return 0;
}