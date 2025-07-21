#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

// Check if it's possible to achieve processing capacity `x` with budget X
auto is_possible = [](ll x, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    ll total_cost = 0;
    int N = A.size();
    
    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all combinations of s and t within reasonable bounds
        for (ll s = 0; s <= B[i] && s * P[i] <= X; ++s) {
            ll remaining = max(0LL, x - A[i] * s);
            ll t = (remaining + B[i] - 1) / B[i]; // ceil division
            if (t >= 0 && s * P[i] + t * Q[i] < min_cost) {
                min_cost = s * P[i] + t * Q[i];
            }
        }

        for (ll t = 0; t <= A[i] && t * Q[i] <= X; ++t) {
            ll remaining = max(0LL, x - B[i] * t);
            ll s = (remaining + A[i] - 1) / A[i]; // ceil division
            if (s >= 0 && t * Q[i] + s * P[i] < min_cost) {
                min_cost = t * Q[i] + s * P[i];
            }
        }

        if (min_cost > X || min_cost == INF) {
            return false;
        }
        total_cost += min_cost;
        if (total_cost > X) {
            return false;
        }
    }

    return total_cost <= X;
};

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search on the minimum processing capacity that can be achieved
    ll low = 0, high = 1;
    while (is_possible(high, X, A, P, B, Q)) {
        high *= 2;
    }

    ll result = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (is_possible(mid, X, A, P, B, Q)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}