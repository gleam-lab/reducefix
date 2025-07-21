#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll compute_cost(ll a, ll b, ll p, ll q, ll k) {
    ll cost = LLONG_MAX;
    // We can use either a or b for any number of widgets, but we need to find the optimal combination.
    // The optimal is min(p * x + q * y) where a*x + b*y >= k and x, y >= 0.
    // To find this, we can iterate over possible x (0 to k/a + 1) and compute y = ceil((k - a*x)/b).
    ll max_x = k / a + 2;
    for (ll x = 0; x <= max_x; ++x) {
        ll remaining = max(k - a * x, 0LL);
        ll y = (remaining + b - 1) / b;
        cost = min(cost, p * x + q * y);
    }
    return cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0, right = 1e10;
    ll answer = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_cost = 0;
        bool feasible = true;
        rep(i, n) {
            ll cost = compute_cost(a[i], b[i], p[i], q[i], mid);
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
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << answer << endl;
    return 0;
}