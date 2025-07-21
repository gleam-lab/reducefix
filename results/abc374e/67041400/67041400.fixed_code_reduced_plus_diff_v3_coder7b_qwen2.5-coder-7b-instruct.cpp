#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve capability W for a given machine
ll min_cost_to_achieve_capability(int N, ll W, ll X,
                                   const vector<ll>& A, const vector<ll>& P,
                                   const vector<ll>& B, const vector<ll>& Q) {
    ll best_cost = X + 1;
    for (int i = 0; i < N; ++i) {
        // Calculate the number of machines needed to achieve capability W for this process
        ll num_machines = (W + A[i] - 1) / A[i];  // Equivalent to ceiling(W / A[i])
        
        // Calculate the remaining capacity after using num_machines
        ll remaining_capacity = W - num_machines * A[i];
        
        // If there is remaining capacity, we need additional machines for the second type
        if (remaining_capacity > 0) {
            ll additional_machines = (remaining_capacity + B[i] - 1) / B[i];  // Ceiling(remaining_capacity / B[i])
            num_machines += additional_machines;
        }
        
        // Calculate the cost for using num_machines
        ll cost = num_machines * P[i];
        
        // Update the best cost found so far
        best_cost = min(best_cost, cost);
    }
    
    return best_cost;
}

// Main function to find the maximum capability W within budget X
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

    // Binary search to find the maximum capability W
    ll lo = 0, hi = X + 1;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (min_cost_to_achieve_capability(N, mid, X, A, P, B, Q) <= X) {
            lo = mid + 1;  // Try for a higher capability
        } else {
            hi = mid;  // Lower capability is not feasible
        }
    }

    // The result is the largest feasible capability which is lo - 1
    cout << lo - 1 << "\n";

    return 0;
}