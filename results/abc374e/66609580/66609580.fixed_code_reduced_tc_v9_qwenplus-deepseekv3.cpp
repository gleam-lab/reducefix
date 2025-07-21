#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x;
ll a[110], b[110], p[110], q[110];

bool check(ll v) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) {
        ll max_possible = 0;
        ll min_cost = LLONG_MAX;
        
        // Calculate maximum possible k for a[i]
        ll max_k = v / a[i];
        for (ll k = 0; k <= max_k; ++k) {
            ll remaining = v - k * a[i];
            if (remaining < 0) continue;
            
            ll m = remaining / b[i];
            ll cost = k * p[i] + m * q[i];
            if (cost < min_cost) {
                min_cost = cost;
            }
            
            // Early exit if we find cost=0 (can't get better)
            if (min_cost == 0) break;
        }
        
        total += min_cost;
        if (total > x) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    
    ll low = 0, high = 1e18;
    ll answer = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << answer << '\n';
    return 0;
}