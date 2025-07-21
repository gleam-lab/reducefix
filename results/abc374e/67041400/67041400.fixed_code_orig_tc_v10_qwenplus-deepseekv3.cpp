#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimal cost to achieve W for each stage
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best = X + 1;
        ll max_x = (W + A[i] - 1) / A[i];
        
        // Function to compute cost for a given x
        auto compute_cost = [&](ll x) {
            if (x < 0) return LLONG_MAX;
            ll rem = W - A[i] * x;
            ll y = rem <= 0 ? 0 : (rem + B[i] - 1) / B[i];
            return P[i] * x + Q[i] * y;
        };

        // Check x = 0
        best = min(best, compute_cost(0));
        if (best > X) return X + 1;

        // Check x = max_x (all S)
        best = min(best, compute_cost(max_x));
        if (best > X) return X + 1;

        // Find x that minimizes the cost
        // The optimal x is around W * Q[i] / (A[i] * Q[i] + B[i] * P[i])
        ll x_opt = (W * Q[i]) / (A[i] * Q[i] + B[i] * P[i]);
        
        // Check x around x_opt
        for (ll x = max(0LL, x_opt - 2); x <= x_opt + 2; x++) {
            if (x > max_x) continue;
            best = min(best, compute_cost(x));
            if (best > X) return X + 1;
        }

        total += best;
        if (total > X) return X + 1;
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search bounds
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi = max(hi, 1LL);

    // Binary search to find the maximum W
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}