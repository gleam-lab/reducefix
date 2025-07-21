#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9 + 10;
const ll inf = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab[i].first;
        ab[i].second = i; // Store original index
    }
    
    for (int i = 0; i < n; i++) {
        cin >> ab[i].second;
    }
    
    sort(ab.begin(), ab.end());

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + ab[i].second;
    }

    ll ans = inf;
    for (int i = k - 1; i < n; i++) {
        int max_a = ab[i].first;
        ll sum_b = prefix_sum[i + 1] - prefix_sum[i - k + 1];
        ans = min(ans, static_cast<ll>(max_a) * sum_b);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}