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

    auto can_achieve = [&](ll x) {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll min_cost = LLONG_MAX;

            // Option 1: Use only machine A
            ll s = (x + A[i] - 1) / A[i]; // ceil(x / A[i])
            if (s <= B[i]) {
                min_cost = min(min_cost, s * P[i]);
            }

            // Option 2: Use only machine B
            ll t = (x + B[i] - 1) / B[i]; // ceil(x / B[i])
            if (t <= A[i]) {
                min_cost = min(min_cost, t * Q[i]);
            }

            // Option 3: Use a combination of both machines A and B
            // Find s and t such that A[i]*s + B[i]*t >= x, s <= B[i], t <= A[i]
            // We can iterate s from 0 to min(B[i], x / A[i] + 1) and find corresponding t
            ll max_s = min(B[i], x / A[i] + 2);
            for (ll s = 0; s <= max_s; ++s) {
                ll remaining = max(0LL, x - A[i] * s);
                ll t = (remaining + B[i] - 1) / B[i];
                if (t <= A[i]) {
                    min_cost = min(min_cost, s * P[i] + t * Q[i]);
                }
            }

            // Similarly, iterate t from 0 to min(A[i], x / B[i] + 1) and find corresponding s
            ll max_t = min(A[i], x / B[i] + 2);
            for (ll t = 0; t <= max_t; ++t) {
                ll remaining = max(0LL, x - B[i] * t);
                ll s = (remaining + A[i] - 1) / A[i];
                if (s <= B[i]) {
                    min_cost = min(min_cost, t * Q[i] + s * P[i]);
                }
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
    ll answer = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (can_achieve(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}