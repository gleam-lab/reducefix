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
            
            // Try all possible numbers of type 1 machines (s)
            // The maximum needed is ceil(x / A[i]) or based on budget
            ll max_s = min(x / A[i] + 1, X / P[i] + 1);
            for (ll s = 0; s <= max_s; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];  // ceil(remaining / B[i])
                if (t < 0) t = 0;
                ll cost = s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            
            // Similarly for type 2 machines
            ll max_t = min(x / B[i] + 1, X / Q[i] + 1);
            for (ll t = 0; t <= max_t; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];  // ceil(remaining / A[i])
                if (s < 0) s = 0;
                ll cost = t * Q[i] + s * P[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            
            if (min_cost == INF) return false;
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