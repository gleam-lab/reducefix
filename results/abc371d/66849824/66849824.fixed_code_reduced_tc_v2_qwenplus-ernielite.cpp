#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

// ... (other definitions remain the same) ...

int main(){
    int N;
    cin >> N;
    vector<ll> P(N+1), X(N);
    P[0] = 0; // Assuming P[0] is always 0, as per the problem description
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        P[i+1] = P[i] + X[i]; // Accumulate prefix sum starting from 1-based index
    }
    map<int, int> x_to_ptr;
    for (int i = 0; i < N; ++i) {
        x_to_ptr.emplace(X[i], i + 1); // Store the 1-based index in the map
    }

    // ... (rest of the code remains the same) ...

    // Now when finding l and r, we need to handle the case where X_l or X_r points to end()
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R; // Read L and R from input
        auto X_l_it = x_to_ptr.lower_bound(L); // Find lower bound for L in x_to_ptr
        auto X_r_it = x_to_ptr.upper_bound(R); // Find upper bound for R in x_to_ptr
        int l = (X_l_it != x_to_ptr.end()) ? X_l_it->second : N + 1; // If X_l is not end(), use its index, otherwise set to N+1 (out of range)
        int r = (X_r_it != x_to_ptr.begin()) ? prev(X_r_it)->second : 0; // If X_r is not beginning(), use previous element's index, otherwise set to 0 (index before start)
        // Note: We're using N+1 as an out-of-range index for l and 0 for r since P array is 0-based but we need 1-based indices for l and r in the prefix sum array P.
        int ans = (l > 1) ? P[r] - P[l-1] : 0; // Adjust for 1-based index in P array and handle edge cases where l is out of range or too close to 1 (should be treated as 0)
        cout << ans << endl; // Output the answer
    }
}