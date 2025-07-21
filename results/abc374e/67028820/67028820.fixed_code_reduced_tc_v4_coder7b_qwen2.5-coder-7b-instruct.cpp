#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> c[i] >> b[i] >> d[i];
    }

    ll l = 0, r = 1e9;
    while (l < r) {
        ll m = (l + r + 1) / 2;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            ll need_s = m / a[i];
            ll need_t = m / b[i];
            ll cost_s = need_s * c[i];
            ll cost_t = need_t * d[i];
            if (cost_s > x || cost_t > x) {
                ok = false;
            } else {
                ll remaining = x - min(cost_s, cost_t);
                if (remaining >= need_s * c[i] - cost_s) {
                    remaining -= need_s * c[i] - cost_s;
                    need_t += remaining / d[i];
                    cost_t = need_t * d[i];
                }
                if (remaining >= need_t * d[i] - cost_t) {
                    remaining -= need_t * d[i] - cost_t;
                    need_s += remaining / c[i];
                    cost_s = need_s * c[i];
                }
                if (max(cost_s, cost_t) > x) {
                    ok = false;
                }
            }
        }
        if (ok) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << l << '\n';

    return 0;
}