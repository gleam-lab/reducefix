#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto feasible = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll min_cost = INF;
            // Try all possible s (number of A machines) up to the point where A[i]*s >= x
            // But to avoid excessive computation, we cap s at the ceiling of (x / A[i])
            ll max_s = (x + A[i] - 1) / A[i];
            max_s = min(max_s, B[i] + 1); // Do not exceed B[i] since t would be zero
            for (ll s = 0; s <= max_s; ++s) {
                ll remaining = x - A[i] * s;
                ll t = 0;
                if (remaining > 0) {
                    t = (remaining + B[i] - 1) / B[i];
                }
                if (t <= Q[i]) { // Ensure t does not exceed Q[i] (assuming Q[i] is the max allowed)
                    min_cost = min(min_cost, s * P[i] + t * Q[i]);
                }
            }
            // Similarly, try all possible t (number of B machines) up to the point where B[i]*t >= x
            ll max_t = (x + B[i] - 1) / B[i];
            max_t = min(max_t, A[i] + 1); // Do not exceed A[i] since s would be zero
            for (ll t = 0; t <= max_t; ++t) {
                ll remaining = x - B[i] * t;
                ll s = 0;
                if (remaining > 0) {
                    s = (remaining + A[i] - 1) / A[i];
                }
                if (s <= P[i]) { // Ensure s does not exceed P[i] (assuming P[i] is the max allowed)
                    min_cost = min(min_cost, t * Q[i] + s * P[i]);
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

    ll low = 0;
    ll high = INF;
    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        if (feasible(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;

    return 0;
}