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

    auto calculate_min_cost = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; i++) {
            ll min_cost = INF;
            // Try all possible s (number of type A machines) from 0 to maximum needed
            ll max_s = min((x + A[i] - 1) / A[i], B[i]);
            for (ll s = 0; s <= max_s; s++) {
                ll remaining = x - A[i] * s;
                if (remaining <= 0) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll t = (remaining + B[i] - 1) / B[i];
                if (t > Q[i]) continue;  // Can't buy more than Q[i] type B machines
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Try all possible t (number of type B machines) from 0 to maximum needed
            ll max_t = min((x + B[i] - 1) / B[i], Q[i]);
            for (ll t = 0; t <= max_t; t++) {
                ll remaining = x - B[i] * t;
                if (remaining <= 0) {
                    min_cost = min(min_cost, t * Q[i]);
                    continue;
                }
                ll s = (remaining + A[i] - 1) / A[i];
                if (s > B[i]) continue;  // Can't buy more than B[i] type A machines
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
            }
            if (min_cost == INF) return false;
            total_cost += min_cost;
            if (total_cost > X) return false;
        }
        return total_cost <= X;
    };

    ll low = 0, high = INF;
    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        if (calculate_min_cost(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    
    cout << low << endl;
    return 0;
}