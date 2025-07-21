#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto can_achieve = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; i++) {
            ll min_cost = INF;
            
            // We need to find s and t such that A[i]*s + B[i]*t >= x
            // And minimize s*P[i] + t*Q[i]
            
            // Maximum possible s we might need (when t=0)
            ll max_s = (x + A[i] - 1) / A[i];
            
            // Maximum possible t we might need (when s=0)
            ll max_t = (x + B[i] - 1) / B[i];
            
            // Try all possible t in [0, max_t] and find corresponding s
            for (ll t = 0; t <= max_t; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
                
                // Early exit if we can't achieve x even with infinite money
                if (min_cost >= INF) return false;
            }
            
            // Try all possible s in [0, max_s] and find corresponding t
            for (ll s = 0; s <= max_s; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
                
                // Early exit if we can't achieve x even with infinite money
                if (min_cost >= INF) return false;
            }
            
            total_cost += min_cost;
            if (total_cost > X) return false;
        }
        return true;
    };

    ll low = 0, high = INF;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (can_achieve(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << low << endl;
    return 0;
}