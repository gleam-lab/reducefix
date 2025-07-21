#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x;
ll a[105], p[105], b[105], q[105];

ll compute_min_cost(ll mid, ll a, ll p, ll b, ll q) {
    ll min_cost = LLONG_MAX;
    ll max_j = min(mid / a + 1, b);
    for (ll j = 0; j <= max_j; ++j) {
        ll remaining = mid - j * a;
        if (remaining < 0) {
            min_cost = min(min_cost, j * p);
            continue;
        }
        ll k = (remaining + b - 1) / b; // ceiling division
        min_cost = min(min_cost, j * p + k * q);
    }
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll l = 0, r = 2e18, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll total_cost = 0;
        bool feasible = true;
        for (int i = 1; i <= n; ++i) {
            ll cost = compute_min_cost(mid, a[i], p[i], b[i], q[i]);
            cost = min(cost, compute_min_cost(mid, b[i], q[i], a[i], p[i]));
            total_cost += cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}