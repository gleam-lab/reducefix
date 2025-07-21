#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

ll calculate_cost(ll a, ll b, ll p, ll q, ll w) {
    ll min_cost = LLONG_MAX;
    // We can't buy more than w/a of type a or w/b of type b
    ll max_a = w / a + 2;
    ll max_b = w / b + 2;
    
    // Limit the search space to reasonable bounds
    max_a = min(max_a, 100000LL);
    max_b = min(max_b, 100000LL);
    
    for (ll cnt_a = 0; cnt_a <= max_a; ++cnt_a) {
        ll remaining = w - cnt_a * a;
        if (remaining < 0) continue;
        
        ll cnt_b = remaining / b;
        if (remaining % b != 0) cnt_b++;
        cnt_b = max(cnt_b, 0LL);
        
        ll total = cnt_a * p + cnt_b * q;
        if (total < min_cost) min_cost = total;
    }
    
    return min_cost;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    ll left = 0, right = x * 1000; // Reasonable upper bound
    ll answer = 0;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            total_cost += calculate_cost(a[i], b[i], p[i], q[i], mid);
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