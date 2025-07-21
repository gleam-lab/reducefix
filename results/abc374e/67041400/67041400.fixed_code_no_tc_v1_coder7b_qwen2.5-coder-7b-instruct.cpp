#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost required to achieve a production capacity of W
ll cost_for_W(int N, ll W, ll X,
              const vector<ll>& A, const vector<ll>& P,
              const vector<ll>& B, const vector<ll>& Q)
{
    ll total_cost = 0;
    for(int i = 0; i < N; i++) {
        // Calculate the minimum cost to produce at least W products per day for process i
        ll best_cost = LLONG_MAX;

        // Iterate over possible numbers of machines S_i and T_i
        for(ll s = 0; s * A[i] <= W; ++s) {
            ll remaining_products = W - s * A[i];
            ll t = (remaining_products + B[i] - 1) / B[i]; // Number of T_i machines needed
            ll current_cost = s * P[i] + t * Q[i];
            if(current_cost < best_cost) {
                best_cost = current_cost;
            }
        }

        total_cost += best_cost;
        if(total_cost > X) return X + 1;  // If total cost exceeds budget, stop early
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
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search bounds
    ll lo = 0, hi = X;  // Upper bound is the maximum possible production with the entire budget

    // Binary search to find the maximum achievable production capacity
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;  // Midpoint calculation to ensure non-decreasing nature
        if(cost_for_W(N, mid, X, A, P, B, Q) <= X) {
            lo = mid;  // Mid point is feasible
        } else {
            hi = mid - 1;  // Mid point is not feasible, adjust upper bound
        }
    }

    cout << lo << "\n";
    return 0;
}