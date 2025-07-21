#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to compute the minimal cost to achieve work W for each engineering step
ll cost_for_W(int N, ll W, ll X,
    const vector<ll>& A, const vector<ll>& P,
    const vector<ll>& B, const vector<ll>& Q)
{
    ll total = 0;
    for(int i = 0; i < N; i++){
        ll best_cost = X + 1;
        ll max_x = (W + A[i] - 1) / A[i]; // Maximum x when only S is used

        // Function to compute cost for a given x
        auto compute_cost = [&](ll x) {
            if (x < 0) return LLONG_MAX;
            ll rem = W - A[i] * x;
            ll y = max(0LL, rem <= 0 ? 0 : (rem + B[i] - 1) / B[i]);
            return P[i] * x + Q[i] * y;
        };

        // Check the boundary cases
        best_cost = min(best_cost, compute_cost(0)); // All T machines
        best_cost = min(best_cost, compute_cost(max_x)); // All S machines

        // Find the optimal x where the cost might be minimized
        if (A[i] != 0 && B[i] != 0) {
            long double x_star = (long double)W * Q[i] / (A[i] * Q[i] + B[i] * P[i]);
            ll x_floor = floor(x_star);
            ll x_ceil = ceil(x_star);

            // Check nearby points around the optimal x
            for (ll x = max(0LL, x_floor - 2); x <= min(max_x, x_floor + 2); ++x) {
                best_cost = min(best_cost, compute_cost(x));
            }
            for (ll x = max(0LL, x_ceil - 2); x <= min(max_x, x_ceil + 2); ++x) {
                best_cost = min(best_cost, compute_cost(x));
            }
        }

        total += best_cost;
        if (total > X) return X + 1; // Early exit if budget exceeded
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

    // Determine the upper bound for binary search
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < N; i++){
        hi += max((X / P[i]) * A[i], (X / Q[i]) * B[i]);
    }
    hi += 1; // To ensure we cover all possible W

    // Binary search to find the maximum W
    while(lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << "\n";
    return 0;
}