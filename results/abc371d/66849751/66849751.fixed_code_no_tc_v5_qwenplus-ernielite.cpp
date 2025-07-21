#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Removed the redundant definitions for loop iterators
// You only need the basic ones (rep and all)

// The rest of the code remains the same...

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N);
    P[0] = 0; // Initialize prefix sum with 0

    // Read the prefix sum array P
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p; // Accumulate prefix sum
    }

    // Read the array X and build a map from X values to their indices
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read X values
        x_to_ptr.emplace(X[i], i); // Store X values in a map with their indices as keys
    }

    // Read queries and process them
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, R; // Query range [L, R]
        cin >> L >> R; // Read query range limits L and R
        auto X_l = x_to_ptr.lower_bound(L); // Find lower bound in map for L
        auto X_r = x_to_ptr.upper_bound(R); // Find upper bound in map for R
        // The rest of the code to find l and r, and calculate the answer remains the same...
        // ... (Your previous code to calculate l, r, and ans) ...
        cout << ans << endl; // Output the answer for each query
    }
}