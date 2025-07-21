#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<ll> p(n), prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        // Find first index where x[i] >= l using lower_bound
        auto left = lower_bound(x.begin(), x.end(), l);
        // Find first index where x[i] > r using upper_bound
        auto right = upper_bound(x.begin(), x.end(), r);

        ll ans = prefix_sum[(int)(right - x.begin())] - prefix_sum[(int)(left - x.begin())];
        cout << ans << '\n';
    }

    return 0;
}