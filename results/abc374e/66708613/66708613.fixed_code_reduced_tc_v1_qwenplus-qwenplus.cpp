#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;
const int inf = 1 << 30;
const ll INF = 1LL << 62;
const ll MOD = 998244353;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto can_achieve = [&](ll capacity) -> bool {
        ll total_cost = 0;
        
        for (int i = 0; i < N; ++i) {
            ll min_cost = INF;
            
            // Try all possible counts of machine A within budget
            for (ll s = 0; s <= B[i] && s * P[i] <= X; ++s) {
                ll remaining = max(0LL, capacity - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i]; // ceil division
                if (t <= B[i]) {
                    min_cost = min(min_cost, s * P[i] + t * Q[i]);
                }
            }
            
            // Try all possible counts of machine B within budget
            for (ll t = 0; t <= A[i] && t * Q[i] <= X; ++t) {
                ll remaining = max(0LL, capacity - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i]; // ceil division
                if (s <= A[i]) {
                    min_cost = min(min_cost, t * Q[i] + s * P[i]);
                }
            }
            
            if (min_cost == INF || total_cost + min_cost > X) {
                return false;
            }
            total_cost += min_cost;
        }
        
        return true;
    };

    // Binary search for maximum achievable capacity
    ll low = 0, high = 1LL << 60;
    while (low < high) {
        ll mid = (high + low + 1) / 2;
        if (can_achieve(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << endl;
    
    return 0;
}