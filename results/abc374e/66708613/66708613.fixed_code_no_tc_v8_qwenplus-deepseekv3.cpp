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
    
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto f = [&](ll x) {
        ll total_cost = 0;
        for(int i = 0; i < N; i++) {
            ll min_cost = INF;
            // We need to find s and t such that A[i]*s + B[i]*t >= x
            // and minimize s*P[i] + t*Q[i]
            
            // Try all possible s up to needed s_max
            ll s_max = (x + A[i] - 1) / A[i];
            ll t_max = (x + B[i] - 1) / B[i];
            
            // Limit the search space to reasonable bounds
            s_max = min(s_max, 100000LL);
            t_max = min(t_max, 100000LL);
            
            for(ll s = 0; s <= s_max; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            
            for(ll t = 0; t <= t_max; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            
            if(min_cost == INF) return false;
            total_cost += min_cost;
            if(total_cost > X) return false;
        }
        return total_cost <= X;
    };

    ll lb = 0, ub = 1;
    // First find a suitable upper bound
    while(f(ub)) ub *= 2;
    
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(f(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    
    cout << lb << endl;
}