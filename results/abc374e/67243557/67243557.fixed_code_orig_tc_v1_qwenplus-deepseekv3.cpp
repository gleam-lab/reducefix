#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_cost(ll a, ll b, ll p, ll q, ll x) {
    ll cost = LLONG_MAX;
    // We can buy x items using any combination of a and b batches
    // The optimal is to minimize the cost: k*p + m*q where k*a + m*b >= x
    // We need to find the minimal such k*p + m*q
    // Since a and b can be up to 100, we can brute-force m in [0, ceil(x/b) + 1]
    ll max_m = (x / b) + 2;
    for (ll m = 0; m <= max_m; ++m) {
        ll remaining = max(x - m * b, 0LL);
        ll k = (remaining + a - 1) / a; // ceil(remaining / a)
        cost = min(cost, k * p + m * q);
    }
    return cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 1e10;
    ll best = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;
        bool feasible = true;
        rep(i, n) {
            ll cost = calculate_cost(a[i], b[i], p[i], q[i], mid);
            if (cost > x) {
                feasible = false;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                feasible = false;
                break;
            }
        }
        if (feasible) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << best << endl;
    return 0;
}