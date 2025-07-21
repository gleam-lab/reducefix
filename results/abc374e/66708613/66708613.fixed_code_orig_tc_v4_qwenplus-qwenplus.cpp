#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;
const ll MOD = 998244353;

int N;
ll X;
vector<ll> A, P, B, Q;

bool can_afford(ll capacity) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all possible s (number of A machines), compute required t
        for (ll s = 0; s <= B[i]; ++s) {
            ll remaining = max(0LL, capacity - A[i] * s);
            ll t = (remaining + B[i] - 1) / B[i];
            if (t > A[i]) continue; // not feasible
            min_cost = min(min_cost, s * P[i] + t * Q[i]);
        }

        // Try all possible t (number of B machines), compute required s
        for (ll t = 0; t <= A[i]; ++t) {
            ll remaining = max(0LL, capacity - B[i] * t);
            ll s = (remaining + A[i] - 1) / A[i];
            if (s > B[i]) continue; // not feasible
            min_cost = min(min_cost, t * Q[i] + s * P[i]);
        }

        if (min_cost == INF || total_cost + min_cost > X)
            return false;

        total_cost += min_cost;
    }
    return true;
}

int main() {
    cin >> N >> X;
    A.resize(N), P.resize(N), B.resize(N), Q.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> P[i] >> B[i] >> Q[i];

    // Check if it's even possible to buy at least one machine per stage
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        if (P[i] > X && Q[i] > X) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    // Binary search for maximum achievable processing capacity
    ll low = 0, high = 1;
    while (can_afford(high)) {
        high *= 2;
        if (high > 1e18) break;
    }

    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (can_afford(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << endl;
    return 0;
}