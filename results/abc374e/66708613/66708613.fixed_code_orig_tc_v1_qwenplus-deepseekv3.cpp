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
            // Check all possible s (number of A machines) up to the needed maximum
            ll max_s = (x + A[i] - 1) / A[i];
            for (ll s = 0; s <= max_s; s++) {
                ll remaining = max(0LL, x - s * A[i]);
                ll t = (remaining + B[i] - 1) / B[i];
                if (t < 0) t = 0;
                ll cost = s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
                // Early exit if cost starts increasing
                if (min_cost == 0) break;
            }
            // Also check all possible t (number of B machines) up to the needed maximum
            ll max_t = (x + B[i] - 1) / B[i];
            for (ll t = 0; t <= max_t; t++) {
                ll remaining = max(0LL, x - t * B[i]);
                ll s = (remaining + A[i] - 1) / A[i];
                if (s < 0) s = 0;
                ll cost = s * P[i] + t * Q[i];
                if (cost < min_cost) {
                    min_cost = cost;
                }
                // Early exit if cost starts increasing
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