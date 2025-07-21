#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;
using P = pair<ll, int>;

int N;
ll X;
vector<ll> A, P, B, Q;

// Function to check if we can achieve processing capacity x with budget X
bool is_possible(ll x) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all possible numbers of machine A (s)
        for (ll s = 0; s <= B[i] && s * P[i] <= X; ++s) {
            ll remaining = max(0LL, x - A[i] * s);
            ll t = (remaining + B[i] - 1) / B[i]; // ceil(remaining / B[i])
            if (t > Q[i]) continue; // not enough budget for this part
            min_cost = min(min_cost, s * P[i] + t * Q[i]);
        }

        // Try all possible numbers of machine B (t)
        for (ll t = 0; t <= A[i] && t * Q[i] <= X; ++t) {
            ll remaining = max(0LL, x - B[i] * t);
            ll s = (remaining + A[i] - 1) / A[i]; // ceil(remaining / A[i])
            if (s > P[i]) continue; // not enough budget for this part
            min_cost = min(min_cost, t * Q[i] + s * P[i]);
        }

        if (min_cost == INF) {
            return false; // Cannot achieve x with this step
        }
        total_cost += min_cost;
        if (total_cost > X) {
            return false; // Total cost exceeds budget
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    A.resize(N), P.resize(N), B.resize(N), Q.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Early check: If even one stage cannot afford the minimum of either machine, output 0
    for (int i = 0; i < N; ++i) {
        if (P[i] > X && Q[i] > X) {
            cout << 0 << '\n';
            return 0;
        }
    }

    // Binary search on maximum achievable processing capacity
    ll low = 0, high = 1e18;
    ll result = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (is_possible(mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}