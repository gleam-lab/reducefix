#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x;
vector<ll> a, b, p, q;

bool canMake(ll mid) {
    double totalCost = 0;
    for (ll i = 0; i < n; ++i) {
        ll temp = mid;
        double s = (double)p[i] / a[i];
        double t = (double)q[i] / b[i];

        if (s < t) {
            ll x = mid / a[i];
            totalCost += x * p[i];
            temp -= x * a[i];
            totalCost += temp * t;
        } else {
            ll x = mid / b[i];
            totalCost += x * q[i];
            temp -= x * b[i];
            totalCost += temp * s;
        }
    }

    return ceil(totalCost) <= x;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (ll i = 0; i < n; ++i) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0, right = 1e18; // Adjusted upper bound to handle larger inputs
    while (left < right) {
        ll mid = (left + right) / 2;
        if (canMake(mid)) right = mid;
        else left = mid + 1;
    }

    cout << left;

    return 0;
}