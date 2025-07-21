#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

// Function to calculate minimum cost to produce 'x' items using packages of size a and b
ll calculate_min_cost(ll a, ll b, ll p, ll q, ll x) {
    ll min_cost = LLONG_MAX;
    // Try all possible combinations of a and b packages
    for (ll k = 0; k <= (x / a) + 1; k++) {
        ll remaining = x - k * a;
        if (remaining < 0) remaining = 0;
        ll l = (remaining + b - 1) / b; // ceil(remaining / b)
        ll total = k * p + l * q;
        if (total < min_cost) {
            min_cost = total;
        }
    }
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll left = 0, right = 1e18;
    ll answer = 0;
    
    // Binary search for the maximum number of widgets that can be produced
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        
        rep(i, n) {
            total_cost += calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) break; // Early exit if already over budget
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