#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll left = 0, right = 1e18, ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_cost = 0;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            ll min_cost = LLONG_MAX;
            // Iterate over possible j (number of times a[i] is used)
            // j can be from 0 to ceil(mid / a[i])
            ll max_j = mid / a[i] + 2;
            for (ll j = 0; j <= max_j; ++j) {
                ll remaining_days = mid - j * a[i];
                if (remaining_days < 0) {
                    remaining_days = 0;
                }
                ll k = (remaining_days + b[i] - 1) / b[i]; // ceil(remaining_days / b[i])
                ll cost = j * p[i] + k * q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
                if (min_cost == 0) break; // Can't get better than 0
            }
            // Also check combinations where b[i] is used first
            ll max_k = mid / b[i] + 2;
            for (ll k = 0; k <= max_k; ++k) {
                ll remaining_days = mid - k * b[i];
                if (remaining_days < 0) {
                    remaining_days = 0;
                }
                ll j = (remaining_days + a[i] - 1) / a[i]; // ceil(remaining_days / a[i])
                ll cost = k * q[i] + j * p[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
                if (min_cost == 0) break; // Can't get better than 0
            }
            total_cost += min_cost;
            if (total_cost > x) {
                possible = false;
                break;
            }
        }
        if (possible) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}