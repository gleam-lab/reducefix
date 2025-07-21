#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int n, x;
vector<ll> a, b, p, q;

bool canMake(ll mid) {
    ld total_cost = 0;
    for (int i = 0; i < n; i++) {
        ll temp = mid;
        ld s = p[i] / (ld)a[i];
        ld t = q[i] / (ld)b[i];

        if (s < t) {
            ll x = mid / a[i];
            total_cost += x * p[i];
            temp -= x * a[i];
            total_cost += temp * t;
        } else {
            ll x = mid / b[i];
            total_cost += x * q[i];
            temp -= x * b[i];
            total_cost += temp * s;
        }
    }

    return ceil(total_cost) <= x;
}

signed main() {
    cin >> n >> x;
    a.resize(n), b.resize(n), p.resize(n), q.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0, right = 1e18;
    while (left < right) {
        ll mid = left + (right - left) / 2;

        if (canMake(mid)) right = mid;
        else left = mid + 1;
    }

    cout << left;

    return 0;
}