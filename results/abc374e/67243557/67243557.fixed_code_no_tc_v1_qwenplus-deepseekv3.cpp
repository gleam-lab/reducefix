#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll x) {
    ll min_cost = LLONG_MAX;
    // Try all possible combinations of machine A (0 to x/a + 1)
    ll max_a = x / a + 2;
    for (ll use_a = 0; use_a <= max_a; use_a++) {
        ll remaining = max(0LL, x - use_a * a);
        ll use_b = (remaining + b - 1) / b;  // ceiling division
        ll total_cost = use_a * p + use_b * q;
        min_cost = min(min_cost, total_cost);
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
        
        rep(i,n) {
            total_cost += calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break;  // Early exit if budget exceeded
        }
        
        if (total_cost <= x) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer;
    return 0;
}