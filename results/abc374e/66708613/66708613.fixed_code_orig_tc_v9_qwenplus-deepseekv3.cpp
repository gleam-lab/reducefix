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
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto feasible = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; i++) {
            ll min_cost = LLONG_MAX;
            // Iterate possible number of type A machines
            ll max_a = min(x / A[i] + 1, B[i] + 1);
            for (ll s = 0; s <= max_a; s++) {
                ll remaining = x - s * A[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, s * P[i]);
                    continue;
                }
                ll t = (remaining + B[i] - 1) / B[i];
                if (t < 0) t = 0;
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
            // Iterate possible number of type B machines
            ll max_b = min(x / B[i] + 1, A[i] + 1);
            for (ll t = 0; t <= max_b; t++) {
                ll remaining = x - t * B[i];
                if (remaining <= 0) {
                    min_cost = min(min_cost, t * Q[i]);
                    continue;
                }
                ll s = (remaining + A[i] - 1) / A[i];
                if (s < 0) s = 0;
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

    ll low = 0;
    ll high = 1LL << 60;
    ll ans = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (feasible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}