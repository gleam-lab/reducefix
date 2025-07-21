#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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
            // We need to find s and t such that A[i]*s + B[i]*t >= x, minimizing s*P[i] + t*Q[i]
            // Since s and t can be up to x / min(A[i], B[i]) + 1, we can limit the search space
            ll max_s = (x + A[i] - 1) / A[i] + 1;
            ll max_t = (x + B[i] - 1) / B[i] + 1;
            // To avoid excessive computation, cap max_s and max_t to reasonable values
            max_s = min(max_s, 200000LL);
            max_t = min(max_t, 200000LL);
            for (ll s = 0; s <= max_s; ++s) {
                ll required_t = max(0LL, (x - A[i] * s + B[i] - 1) / B[i]);
                if (required_t > max_t) continue;
                ll cost = s * P[i] + required_t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
                if (min_cost == 0) break;
            }
            for (ll t = 0; t <= max_t; ++t) {
                ll required_s = max(0LL, (x - B[i] * t + A[i] - 1) / A[i]);
                if (required_s > max_s) continue;
                ll cost = required_s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
                if (min_cost == 0) break;
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
        ll mid = (ub + lb) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    
    cout << lb << endl;
    return 0;
}