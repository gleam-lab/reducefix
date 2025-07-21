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

    auto f = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll min_cost = LLONG_MAX;
            // Check all possible s (number of A operations)
            // The maximum s needed is ceil(x / A[i]) or Q[i] / any other relevant constraint
            // To optimize, we limit s to up to (x + A[i] - 1) / A[i]
            ll max_s = min((x + A[i] - 1) / A[i], B[i]);
            for (ll s = 0; s <= max_s; ++s) {
                ll remaining = x - A[i] * s;
                if (remaining <= 0) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll t = (remaining + B[i] - 1) / B[i];
                if (t > Q[i]) continue; // t cannot exceed Q[i]
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Similarly, check all possible t (number of B operations)
            ll max_t = min((x + B[i] - 1) / B[i], A[i]);
            for (ll t = 0; t <= max_t; ++t) {
                ll remaining = x - B[i] * t;
                if (remaining <= 0) {
                    min_cost = min(min_cost, t * Q[i]);
                    continue;
                }
                ll s = (remaining + A[i] - 1) / A[i];
                if (s > P[i]) continue; // s cannot exceed P[i]
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
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

    ll low = 0, high = 1LL << 60;
    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        if (f(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;
    return 0;
}