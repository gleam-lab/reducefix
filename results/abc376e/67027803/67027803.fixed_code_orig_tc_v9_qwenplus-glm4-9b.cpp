#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    sort(ab.begin(), ab.end());

    if (k == 1) {
        ll ans = 1e18;
        for (int i = 0; i < n; i++) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }

    ll ans = 1e18;
    if (k == 2) {
        // Special case when k = 2, find the two smallest B_i values
        ll sum = ab[0].second + ab[1].second;
        ans = min(ans, ab[0].first * sum);
    } else {
        // General case for k > 2
        ll sum = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += ab[i].second;
        }
        for (int i = k - 1; i < n; i++) {
            auto [a, b] = ab[i];
            ans = min(ans, (sum + b) * a);
            sum += ab[i].second - ab[i - 1].second;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) solve();
}