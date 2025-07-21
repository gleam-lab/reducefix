#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll left = 0, right = 1e18, ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total = 0;
        bool valid = true;
        
        for (int i = 0; i < n && valid; i++) {
            ll min_cost = LLONG_MAX;
            
            // Calculate using a[i] first
            ll max_j = min(mid / a[i], b[i]);
            for (ll j = 0; j <= max_j; j++) {
                ll remaining = mid - j * a[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * p[i]);
                } else {
                    ll k = (remaining + b[i] - 1) / b[i];  // ceil division
                    min_cost = min(min_cost, j * p[i] + k * q[i]);
                }
            }
            
            // Calculate using b[i] first
            ll max_k = min(mid / b[i], a[i]);
            for (ll k = 0; k <= max_k; k++) {
                ll remaining = mid - k * b[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, k * q[i]);
                } else {
                    ll j = (remaining + a[i] - 1) / a[i];  // ceil division
                    min_cost = min(min_cost, k * q[i] + j * p[i]);
                }
            }
            
            total += min_cost;
            if (total > x) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}