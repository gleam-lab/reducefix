#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
using ll = long long;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto can_achieve = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll min_cost = LLONG_MAX;
            // Iterate possible s (number of A machines)
            // Limit s to x / A[i] + 1 to avoid excessive iterations
            ll max_s = min(x / A[i] + 1, B[i]);
            for (ll s = 0; s <= max_s; ++s) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];  // ceil(remaining / B[i])
                if (t < 0) t = 0;
                if (t > Q[i]) continue;  // Ensure t doesn't exceed Q[i] (but Q[i] is the cost per B machine)
                ll cost = s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            // Similarly iterate possible t (number of B machines)
            ll max_t = min(x / B[i] + 1, A[i]);
            for (ll t = 0; t <= max_t; ++t) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];  // ceil(remaining / A[i])
                if (s < 0) s = 0;
                if (s > P[i]) continue;  // Ensure s doesn't exceed P[i] (but P[i] is the cost per A machine)
                ll cost = t * Q[i] + s * P[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            if (min_cost == LLONG_MAX) {
                return false;
            }
            total_cost += min_cost;
            if (total_cost > X) {
                return false;
            }
        }
        return total_cost <= X;
    };

    ll lb = 0, ub = 1LL << 60;
    while (lb < ub) {
        ll mid = lb + (ub - lb + 1) / 2;
        if (can_achieve(mid)) {
            lb = mid;
        } else {
            ub = mid - 1;
        }
    }
    cout << lb << endl;
    return 0;
}