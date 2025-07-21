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
        bool feasible = true;

        for (int i = 0; i < n; ++i) {
            ll min_cost = LLONG_MAX;
            // Case 1: Use j operations of A, fill the rest with B
            ll max_j = min(mid / a[i], b[i]);
            for (ll j = 0; j <= max_j; ++j) {
                ll remaining_time = max(0LL, mid - j * a[i]);
                ll k = (remaining_time + b[i] - 1) / b[i];
                if (k > q[i]) continue; // Ensure k does not exceed max B operations
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }
            // Case 2: Use k operations of B, fill the rest with A
            ll max_k = min(mid / b[i], a[i]);
            for (ll k = 0; k <= max_k; ++k) {
                ll remaining_time = max(0LL, mid - k * b[i]);
                ll j = (remaining_time + a[i] - 1) / a[i];
                if (j > p[i]) continue; // Ensure j does not exceed max A operations
                min_cost = min(min_cost, k * q[i] + j * p[i]);
            }
            if (min_cost == LLONG_MAX) {
                feasible = false;
                break;
            }
            total_cost += min_cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }

        if (feasible) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}