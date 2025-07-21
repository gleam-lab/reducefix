#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main(){
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto f = [&](ll x) {
        ll total_cost = 0;
        for(int i = 0; i < N; i++) {
            ll min_cost = INF;
            
            // Optimal s is min(s) where A[i]*s >= x - B[i]*t
            // We can calculate the optimal s and t for each process
            // To find the minimal cost combination, we can consider:
            // 1. Use only A machines: s = ceil(x/A[i]), t = 0
            // 2. Use only B machines: t = ceil(x/B[i]), s = 0
            // 3. Use combination where A[i]*s + B[i]*t >= x
            
            // Option 1: Use only A machines
            ll s1 = (x + A[i] - 1) / A[i];
            s1 = min(s1, B[i]);  // Can't use more than B[i] A machines
            ll cost1 = s1 * P[i];
            
            // Option 2: Use only B machines
            ll t2 = (x + B[i] - 1) / B[i];
            t2 = min(t2, A[i]);  // Can't use more than A[i] B machines
            ll cost2 = t2 * Q[i];
            
            // Option 3: Find optimal combination
            // We can find s that minimizes s*P[i] + t*Q[i]
            // where t = ceil((x - A[i]*s)/B[i])
            // But we need to ensure s <= B[i] and t >= 0
            
            // To find minimal cost, we can iterate over possible s values
            // But instead of full iteration, we can find the optimal s
            // The optimal s is approximately where P[i]/A[i] ≈ Q[i]/B[i]
            
            ll best_s = min((x * Q[i]) / (A[i] * Q[i] + B[i] * P[i]), B[i]);
            for(ll s = max(0LL, best_s - 2); s <= min(B[i], best_s + 2); s++) {
                if(A[i] * s >= x) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll remaining = x - A[i] * s;
                if(remaining <= 0) continue;
                ll t = (remaining + B[i] - 1) / B[i];
                t = min(t, A[i]);
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            
            min_cost = min({min_cost, cost1, cost2});
            if(min_cost == INF) return false;
            total_cost += min_cost;
            if(total_cost > X) return false;
        }
        return total_cost <= X;
    };

    ll left = 0, right = INF;
    while(left < right) {
        ll mid = left + (right - left + 1) / 2;
        if(f(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
   
    cout << left << endl;
}