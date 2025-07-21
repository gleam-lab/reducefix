#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x, a[105], p[105], b[105], q[105];

ll calculate_cost(ll days) {
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        ll min_cost = LLONG_MAX;
        // We can find the optimal j by considering the ratio of prices
        // Instead of checking all possible j values up to b[i] or a[i]
        
        // Optimal j for buying a[i] days first
        ll max_j = days / a[i] + 2;
        for (ll j = max(0LL, max_j - 100); j <= min(max_j + 100, b[i]); j++) {
            ll remaining = days - j * a[i];
            if (remaining <= 0) {
                min_cost = min(min_cost, j * p[i]);
            } else {
                ll k = (remaining + b[i] - 1) / b[i];
                min_cost = min(min_cost, j * p[i] + k * q[i]);
            }
        }
        
        // Optimal j for buying b[i] days first
        max_j = days / b[i] + 2;
        for (ll j = max(0LL, max_j - 100); j <= min(max_j + 100, a[i]); j++) {
            ll remaining = days - j * b[i];
            if (remaining <= 0) {
                min_cost = min(min_cost, j * q[i]);
            } else {
                ll k = (remaining + a[i] - 1) / a[i];
                min_cost = min(min_cost, j * q[i] + k * p[i]);
            }
        }
        
        total += min_cost;
        if (total > x) break; // Early exit if already over budget
    }
    return total;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    ll l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll cost = calculate_cost(mid);
        if (cost <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}