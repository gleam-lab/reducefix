#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll target) {
    ll min_cost = LLONG_MAX;
    // Try all possible combinations of a and b items that sum up to >= target
    // We only need to try up to target/b + 1 for b items since beyond that is redundant
    ll max_b = target / b + 2;
    for (ll k = 0; k <= max_b; ++k) {
        ll remaining = max(target - k * b, 0LL);
        ll needed_a = (remaining + a - 1) / a;  // ceiling division
        ll cost = k * q + needed_a * p;
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll left = 0, right = 1e18;
    ll answer = 0;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            total_cost += calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break;  // Early exit if already over budget
        }
        
        if (total_cost <= x) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}