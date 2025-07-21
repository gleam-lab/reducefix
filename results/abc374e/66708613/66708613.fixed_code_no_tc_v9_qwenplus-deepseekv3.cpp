#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 62;

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
            // Case 1: Use only A[i] machines
            ll s = (x + A[i] - 1) / A[i];
            if (s >= 0) {
                min_cost = min(min_cost, s * P[i]);
            }
            // Case 2: Use only B[i] machines
            ll t = (x + B[i] - 1) / B[i];
            if (t >= 0) {
                min_cost = min(min_cost, t * Q[i]);
            }
            // Case 3: Use some combination of A[i] and B[i] machines
            // Find s such that A[i]*s + B[i]*t >= x, where t = max(0, (x - A[i]*s + B[i] - 1) / B[i])
            // We need to find s that minimizes s*P[i] + t*Q[i]
            // Since t = max(0, ceil((x - A[i]*s)/B[i]))
            // The optimal s is around x / (A[i] + B[i])
            // So we can check s around this value to find the minimum cost
            ll optimal_s = x / (A[i] + B[i]);
            for (ll s = max(0LL, optimal_s - 2); s <= optimal_s + 2; s++) {
                if (s < 0) continue;
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
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

    ll lb = 0, ub = INF;
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