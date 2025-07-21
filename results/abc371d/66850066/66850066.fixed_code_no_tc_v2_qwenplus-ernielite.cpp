#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1); // Initialize prefix sum array with one extra element at index 0
    P[0] = 0; // Initialize prefix sum at index 0 with 0
    for (int i = 1; i <= N; ++i) {
        ll p;
        cin >> p;
        P[i] = P[i - 1] + p; // Calculate prefix sum
    }
    
    vector<int> X(N); // Array to store the values from input
    map<int, int> x_to_ptr; // Map to store X values and their corresponding indices
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read X values into the array
        x_to_ptr.emplace(X[i], i); // Store X values and their indices in the map
    }
    
    int Q;
    cin >> Q; // Read number of queries
    for (int q = 0; q < Q; ++q) {
        int L, R; // Read query range values L and R
        cin >> L >> R;
        // Check if L or R are valid indices in the map (X array)
        auto X_l_it = x_to_ptr.lower_bound(L);
        auto X_r_it = x_to_ptr.upper_bound(R);
        if (X_l_it == x_to_ptr.end() || X_r_it == x_to_ptr.begin()) {
            // If L is not found or R is found at the beginning of the map (invalid range)
            cout << "0" << endl; // Output 0 or appropriate message/error handling
            continue; // Skip to next query if invalid range is found
        }
        // Find indices corresponding to L and R in the map (X array)
        int l = (*X_l_it).second; // Index of the first element in range (inclusive)
        int r = X_r_it == x_to_ptr.end() ? N : (*X_r_it).second - 1; // Index of one before the last element in range (exclusive)
        // Check if l and r are valid indices within P array bounds (0-based indexing)
        if (l < 0 || r >= N) {
            // Handle invalid indices or appropriate error handling if needed
            continue; // Skip to next query or output appropriate message/error handling
        }
        // Calculate and output the difference in prefix sum at indices l and r (inclusive)
        ll ans = P[r + 1] - P[l]; // Use r+1 because we want to include R in the range (exclusive) when calculating prefix sum difference
        cout << ans << endl; // Output answer for current query
    }
    return 0; // Return 0 to indicate successful execution (not strictly necessary in main function)
}