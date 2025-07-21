#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

const ll INF = 1e18;

ll calculate_min_cost(ll a, ll b, ll p, ll q, ll x) {
    vector<ll> dp(x + 1, INF);
    dp[0] = 0;
    for (ll i = 1; i <= x; ++i) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + p);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + q);
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll left = 0, right = 1e18;
    ll best = 0;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll total_cost = 0;
        bool possible = true;
        
        for (int i = 0; i < n; ++i) {
            ll cost = calculate_min_cost(a[i], b[i], p[i], q[i], mid);
            if (cost >= INF) {
                possible = false;
                break;
            }
            total_cost += cost;
            if (total_cost > x) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            best = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << best << endl;
    return 0;
}