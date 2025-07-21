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

    ll low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total = 0;
        bool valid = true;
        
        for (int i = 0; i < n; i++) {
            ll min_cost = LLONG_MAX;
            
            // Calculate the maximum possible j for option a
            ll max_j = min(mid / a[i], b[i]);
            for (ll j = max(0LL, max_j - 100); j <= max_j + 100 && j <= b[i]; j++) {
                if (j < 0) continue;
                ll remaining = mid - j * a[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * p[i]);
                } else {
                    ll k = (remaining + b[i] - 1) / b[i]; // ceil division
                    if (k <= q[i]) {
                        min_cost = min(min_cost, j * p[i] + k * q[i]);
                    }
                }
            }
            
            // Calculate the maximum possible j for option b
            max_j = min(mid / b[i], a[i]);
            for (ll j = max(0LL, max_j - 100); j <= max_j + 100 && j <= a[i]; j++) {
                if (j < 0) continue;
                ll remaining = mid - j * b[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, j * q[i]);
                } else {
                    ll k = (remaining + a[i] - 1) / a[i]; // ceil division
                    if (k <= p[i]) {
                        min_cost = min(min_cost, j * q[i] + k * p[i]);
                    }
                }
            }
            
            if (min_cost == LLONG_MAX) {
                valid = false;
                break;
            }
            total += min_cost;
            if (total > x) {
                valid = false;
                break;
            }
        }
        
        if (valid && total <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}