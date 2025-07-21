#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the cost for achieving a given production capacity W for a single process
ll cost_for_single_process(int A, int B, int P, int Q, int W) {
    if (W == 0) return 0;
    
    // Calculate the minimum cost to achieve at least W products
    ll min_cost = LLONG_MAX;
    for (int x = 0; x <= W / A; ++x) {
        int remaining = W - x * A;
        int y = (remaining + B - 1) / B;
        ll cost = x * P + y * Q;
        min_cost = min(min_cost, cost);
    }
    return min_cost;
}

// Function to calculate the total cost for achieving a given production capacity W for all processes
ll total_cost(vector<int>& A, vector<int>& P, vector<int>& B, vector<int>& Q, int W) {
    ll total = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        total += cost_for_single_process(A[i], B[i], P[i], Q[i], W);
        if (total > W) return LLONG_MAX; // If total cost exceeds budget, return a large value
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll X;
    cin >> N >> X;
    vector<int> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Determine the upper bound for binary search
    int max_production = 0;
    for (int i = 0; i < N; ++i) {
        max_production += max(A[i], B[i]);
    }

    // Perform binary search
    int lo = 0, hi = max_production + 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (total_cost(A, P, B, Q, mid) <= X) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}