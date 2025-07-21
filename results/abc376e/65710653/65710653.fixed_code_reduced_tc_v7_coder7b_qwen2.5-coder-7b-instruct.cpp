#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pll> a(n);
        vector<ll> b(n);

        rep(i, n) {
            cin >> a[i].first;
        }

        rep(i, n) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll max_a = 0;
        ll sum_b = 0;
        for (int i = 0; i < k; ++i) {
            max_a = max(max_a, a[i].first);
            sum_b += b[i];
        }

        ll ans = max_a * sum_b;

        for (int i = k; i < n; ++i) {
            max_a = max(max_a, a[i].first);
            sum_b += b[i] - b[i - k];
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}