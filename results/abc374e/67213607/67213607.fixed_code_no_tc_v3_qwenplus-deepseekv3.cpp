#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll total = 0;
        bool possible = true;

        for (int i = 0; i < n && possible; i++) {
            ll min_cost = LLONG_MAX;
            
            // We can find the optimal j by solving the equation or using binary search
            // Here we'll use a more efficient approach to find the minimal cost
            ll max_j = min(mid / a[i], b[i]);
            for (ll j = max(0LL, max_j - 100); j <= min(max_j + 100, b[i]); j++) {
                ll remaining = mid - j * a[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * p[i]);
                } else {
                    ll k = (remaining + b[i] - 1) / b[i]; // ceil division
                    min_cost = min(min_cost, j * p[i] + k * q[i]);
                }
            }

            max_j = min(mid / b[i], a[i]);
            for (ll j = max(0LL, max_j - 100); j <= min(max_j + 100, a[i]); j++) {
                ll remaining = mid - j * b[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * q[i]);
                } else {
                    ll k = (remaining + a[i] - 1) / a[i]; // ceil division
                    min_cost = min(min_cost, j * q[i] + k * p[i]);
                }
            }

            if (min_cost == LLONG_MAX) {
                possible = false;
                break;
            }
            total += min_cost;
            if (total > x) {
                possible = false;
                break;
            }
        }

        if (possible) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}