#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum cost to achieve at least 'target' production capacity
ll min_cost_to_target(int N, ll target, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    vector<pair<ll, ll>> costs;
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0 && B[i] == 0) continue; // Skip processes that cannot produce anything
        costs.emplace_back(P[i], A[i]);
        costs.emplace_back(Q[i], B[i]);
    }
    
    sort(costs.begin(), costs.end()); // Sort by cost per product
    
    ll total_cost = 0;
    ll total_products = 0;
    for (auto& [cost, rate] : costs) {
        ll needed_units = (target + rate - 1) / rate; // Ceiling division
        total_cost += needed_units * cost;
        total_products += needed_units * rate;
        
        if (total_products >= target) break;
    }
    
    return total_cost <= target ? total_cost : numeric_limits<ll>::max();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search for the maximum production capacity
    ll lo = 0, hi = X + 1; // Upper bound is X because the maximum capacity cannot exceed the budget
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (min_cost_to_target(N, mid, A, P, B, Q) <= X) {
            lo = mid;  // mid is achievable
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}