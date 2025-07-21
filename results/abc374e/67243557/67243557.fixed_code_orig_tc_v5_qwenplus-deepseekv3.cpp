#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll compute_min_cost(ll a, ll b, ll p, ll q, ll x) {
    // We need to compute the minimum cost to produce x items using a and b
    const ll INF = 1e18;
    ll cost = INF;
    // We can produce x items using some combination of a and b
    // The maximum number of a's we might use is ceil(x / a)
    // Similarly for b's, ceil(x / b)
    // But to optimize, we can limit the search space
    ll max_a = (x + a - 1) / a;
    ll max_b = (x + b - 1) / b;
    // Iterate over possible counts of a (up to max_a)
    // For each a_count, compute the required b_count and total cost
    for (ll a_count = 0; a_count <= max_a; ++a_count) {
        ll remaining = x - a_count * a;
        if (remaining < 0) remaining = 0;
        ll b_count = (remaining + b - 1) / b;
        if (a_count * a + b_count * b >= x) {
            cost = min(cost, a_count * p + b_count * q);
        }
    }
    return cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll low = 0, high = 1e18;
    ll best = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total_cost = 0;
        bool feasible = true;
        for (int i = 0; i < n; ++i) {
            ll cost = compute_min_cost(a[i], b[i], p[i], q[i], mid);
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