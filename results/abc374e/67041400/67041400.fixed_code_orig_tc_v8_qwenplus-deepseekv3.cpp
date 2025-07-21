#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to compute the minimum cost to achieve W for all machines within budget X
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        ll min_cost = X + 1;
        ll max_x = (W + A[i] - 1) / A[i];
        
        // Function to compute cost for a given x
        auto compute_cost = [&](ll x) {
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            return P[i] * x + Q[i] * y;
        };
        
        // Check x = 0 (all type T)
        ll cost = compute_cost(0);
        if (cost < min_cost) min_cost = cost;
        
        // Check x = max_x (all type S)
        cost = compute_cost(max_x);
        if (cost < min_cost) min_cost = cost;
        
        // Find optimal x_star where the cost is minimized
        // The optimal x minimizes P[i]*x + Q[i]*y, where y is (W - A[i]*x)/B[i]
        // The derivative of the cost with respect to x gives the optimal x
        if (A[i] * Q[i] != B[i] * P[i]) {
            ll x_star = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
            for (ll x = max(0LL, x_star - 1); x <= x_star + 1; ++x) {
                if (x >= 0 && x <= max_x) {
                    cost = compute_cost(x);
                    if (cost < min_cost) min_cost = cost;
                }
            }
        }
        
        total_cost += min_cost;
        if (total_cost > X) return X + 1;
    }
    return total_cost;
}

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

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for (int i = 0; i < N; ++i) {
        ll max_possible = max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
        hi = max(hi, max_possible);
    }
    hi += 1;  // Ensure upper bound is inclusive

    // Binary search to find the maximum W
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << lo - 1 << "\n";
    return 0;
}