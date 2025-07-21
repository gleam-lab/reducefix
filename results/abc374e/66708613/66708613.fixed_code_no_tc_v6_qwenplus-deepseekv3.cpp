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

    auto f = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; i++) {
            ll min_cost = INF;
            // The maximum number of type A machines needed is when only type A is used
            ll max_s = min((x + A[i] - 1) / A[i], B[i]);
            for (ll s = 0; s <= max_s; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                if (t < 0) t = 0;
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Similarly, the maximum number of type B machines needed is when only type B is used
            ll max_t = min((x + B[i] - 1) / B[i], A[i]);
            for (ll t = 0; t <= max_t; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                if (s < 0) s = 0;
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
            }
            if (min_cost == INF) return false;
            total_cost += min_cost;
            if (total_cost > X) return false;
        }
        return true;
    };

    ll lb = 0, ub = 0;
    // Compute upper bound: sum of maximum possible capacities
    for (int i = 0; i < N; i++) {
        ub += max(A[i] * B[i], B[i] * A[i]);
    }
    // Binary search to find the maximum x such that f(x) is true
    while (lb < ub) {
        ll mid = (lb + ub + 1) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid - 1;
        }
    }
    
    cout << lb << endl;
    return 0;
}