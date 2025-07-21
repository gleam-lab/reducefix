#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x;
ll a[105], p[105], b[105], q[105];

ll compute_min_cost(ll days, ll ai, ll pi, ll bi, ll qi) {
    ll min_cost = LLONG_MAX;
    ll max_k = days / ai + 2;
    for (ll k = 0; k <= max_k; ++k) {
        ll remaining_days = days - k * ai;
        if (remaining_days <= 0) {
            min_cost = min(min_cost, k * pi);
            continue;
        }
        ll l = (remaining_days + bi - 1) / bi;
        min_cost = min(min_cost, k * pi + l * qi);
    }
    max_k = days / bi + 2;
    for (ll k = 0; k <= max_k; ++k) {
        ll remaining_days = days - k * bi;
        if (remaining_days <= 0) {
            min_cost = min(min_cost, k * qi);
            continue;
        }
        ll l = (remaining_days + ai - 1) / ai;
        min_cost = min(min_cost, k * qi + l * pi);
    }
    return min_cost;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    ll left = 0, right = 1e18, ans = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        bool feasible = true;
        for (int i = 0; i < n; ++i) {
            ll cost = compute_min_cost(mid, a[i], p[i], b[i], q[i]);
            if (cost > x) {
                feasible = false;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }
        if (feasible && total_cost <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}