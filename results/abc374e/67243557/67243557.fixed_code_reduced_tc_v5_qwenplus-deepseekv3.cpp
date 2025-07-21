#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_cost(ll a, ll b, ll p, ll q, ll w) {
    ll min_cost = LLONG_MAX;
    // Try all possible combinations of a and b operations to produce w items
    // Since a*b might be large, we limit the loop to sqrt(w) iterations
    ll max_a = w / a + 2;
    ll max_b = w / b + 2;
    for (ll cnt_a = 0; cnt_a <= max_a; cnt_a++) {
        ll remaining = w - cnt_a * a;
        if (remaining < 0) remaining = 0;
        ll cnt_b = (remaining + b - 1) / b;  // ceiling division
        ll total_cost = cnt_a * p + cnt_b * q;
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
    }
    for (ll cnt_b = 0; cnt_b <= max_b; cnt_b++) {
        ll remaining = w - cnt_b * b;
        if (remaining < 0) remaining = 0;
        ll cnt_a = (remaining + a - 1) / a;  // ceiling division
        ll total_cost = cnt_a * p + cnt_b * q;
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
    }
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll left = 0, right = 1e18;
    ll answer = 0;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        
        rep(i,n) {
            total_cost += calculate_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break;  // Early termination
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