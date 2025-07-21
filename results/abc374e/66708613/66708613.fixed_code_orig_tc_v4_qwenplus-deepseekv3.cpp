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
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto check = [&](ll x) -> bool {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll min_cost = INF;
            // Try all possible s (number of A machines) up to needed
            ll max_s = (x + A[i] - 1) / A[i];
            max_s = min(max_s, B[i] + 1);
            for (ll s = 0; s <= max_s; ++s) {
                ll remaining = x - A[i] * s;
                if (remaining <= 0) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll t = (remaining + B[i] - 1) / B[i];
                if (t > Q[i]) continue;  // t cannot exceed Q[i]
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Try all possible t (number of B machines) up to needed
            ll max_t = (x + B[i] - 1) / B[i];
            max_t = min(max_t, A[i] + 1);
            for (ll t = 0; t <= max_t; ++t) {
                ll remaining = x - B[i] * t;
                if (remaining <= 0) {
                    min_cost = min(min_cost, t * Q[i]);
                    continue;
                }
                ll s = (remaining + A[i] - 1) / A[i];
                if (s > P[i]) continue;  // s cannot exceed P[i]
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
            }
            if (min_cost == INF) return false;
            total_cost += min_cost;
            if (total_cost > X) return false;
        }
        return total_cost <= X;
    };

    ll lb = 0, ub = 1LL << 60;
    if (!check(lb)) {
        cout << 0 << endl;
        return 0;
    }

    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (check(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    cout << lb << endl;
    return 0;
}