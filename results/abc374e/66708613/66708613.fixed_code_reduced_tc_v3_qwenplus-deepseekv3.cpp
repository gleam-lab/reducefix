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

    // Check if we can buy at least one machine for each step
    bool can_buy = true;
    for (int i = 0; i < N; i++) {
        if (X < P[i] && X < Q[i]) {
            can_buy = false;
            break;
        }
    }

    if (!can_buy || X == 0) {
        cout << 0 << endl;
        return 0;
    }

    auto f = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; i++) {
            ll min_cost = INF;
            // Try all possible s (number of type A machines) up to the point where A[i]*s >= x
            for (ll s = 0; s <= (x + A[i] - 1) / A[i]; s++) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                if (t < 0) t = 0;
                ll cost = s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
            }
            // Try all possible t (number of type B machines) up to the point where B[i]*t >= x
            for (ll t = 0; t <= (x + B[i] - 1) / B[i]; t++) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                if (s < 0) s = 0;
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

    ll lb = 0, ub = 1;
    // Find an upper bound where f(ub) is false
    while (f(ub)) {
        ub *= 2;
    }

    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        if (f(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << lb << endl;
    return 0;
}