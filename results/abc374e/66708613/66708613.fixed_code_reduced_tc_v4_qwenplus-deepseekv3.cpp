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
            // Try all possible s (number of type A machines) to find the minimal cost
            // We can limit s to x / A[i] + 1 to cover all possible s that could contribute to x
            ll max_s = min(x / A[i] + 1, B[i]);
            for (ll s = 0; s <= max_s; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                t = min(t, A[i]);
                ll cost = s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            // Similarly, try all possible t (number of type B machines)
            ll max_t = min(x / B[i] + 1, A[i]);
            for (ll t = 0; t <= max_t; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                s = min(s, B[i]);
                ll cost = t * Q[i] + s * P[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            if (min_cost == INF) {
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
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout << lb << endl;
}