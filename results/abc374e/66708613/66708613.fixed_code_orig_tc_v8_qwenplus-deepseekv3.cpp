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

    auto f = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll min_cost = INF;
            // Try all possible s (number of A machines) up to a reasonable limit
            for (ll s = 0; s <= 100; ++s) {
                ll remaining = x - A[i] * s;
                if (remaining <= 0) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll t = (remaining + B[i] - 1) / B[i];
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Try all possible t (number of B machines) up to a reasonable limit
            for (ll t = 0; t <= 100; ++t) {
                ll remaining = x - B[i] * t;
                if (remaining <= 0) {
                    min_cost = min(min_cost, t * Q[i]);
                    continue;
                }
                ll s = (remaining + A[i] - 1) / A[i];
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
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

    if (lb == 0 && !f(1)) {
        cout << 0 << endl;
    } else {
        cout << lb << endl;
    }
    return 0;
}