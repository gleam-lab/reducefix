#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;
const int inf = 1 << 30;
const ll INF = 1LL << 62;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto can_achieve = [&](ll capacity) -> bool {
        ll total_cost = 0;
        
        for(int i = 0; i < N; ++i) {
            ll min_cost = INF;
            
            // Try all possible number of type A machines (up to where it makes sense)
            for(ll s = 0; s * A[i] <= capacity + B[i]; ++s) {
                ll remaining = max(0LL, capacity - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i]; // ceil division
                if(t > INF || s > INF) continue; // prevent overflow
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
                if(min_cost > X) break; // No need to continue if already over budget
            }
            
            // Try all possible number of type B machines
            for(ll t = 0; t * B[i] <= capacity + A[i]; ++t) {
                ll remaining = max(0LL, capacity - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i]; // ceil division
                if(t > INF || s > INF) continue; // prevent overflow
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
                if(min_cost > X) break; // No need to continue if already over budget
            }
            
            if(min_cost == INF) return false;
            total_cost += min_cost;
            if(total_cost > X) return false;
        }
        
        return total_cost <= X;
    };

    // Binary search for maximum achievable processing capacity
    ll low = 0, high = 1e18;
    ll answer = 0;
    
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(can_achieve(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}