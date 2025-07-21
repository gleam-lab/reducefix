#include <bits/stdc++.h>
using namespace std;

// No changes needed here

int main() {
    int N;
    cin >> N; // Read the number of elements in the array X
    vector<long long> P(N + 1, 0); // Initialize prefix sum array P with 0s
    vector<long long> X(N); // Array X to store the elements

    // Read the elements of X and calculate the prefix sum P
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        P[i + 1] = P[i] + X[i]; // Update prefix sum P
    }

    // Map X elements to their indices in a more efficient manner (avoiding multiple inserts)
    map<int, int> x_to_ptr; // Use a map to store X values as keys and their indices as values
    for (int i = 0; i < N; ++i) {
        x_to_ptr[X[i]] = i; // Insert X values in ascending order (important for lower_bound and upper_bound to work correctly)
    }

    // Printing out the map is optional and can be removed if not needed for further processing
    // for (const auto& [k, v] : x_to_ptr) {
    //     cout << "X_i is " << k << " and i is " << v << endl;
    // }

    int Q; // Number of queries
    cin >> Q; // Read the number of queries

    // Process queries to find the difference in prefix sums given a range [L, R]
    for (int q = 0; q < Q; ++q) {
        int L, R; // Left and right bounds of the query range
        cin >> L >> R; // Read the query range bounds

        // Find the indices corresponding to L and R in the map x_to_ptr
        auto X_l_it = x_to_ptr.lower_bound(L); // Find the first element greater than or equal to L
        auto X_r_it = x_to_ptr.upper_bound(R); // Find the first element greater than R (exclusive)

        // Check if we have reached the end of the map (i.e., no element greater than R)
        int l = (X_l_it != x_to_ptr.end()) ? X_l_it->second : N; // If L is not found, set l to N (out of bounds)
        int r = (X_r_it != x_to_ptr.begin()) ? prev(X_r_it)->second : 0; // If R is the first element, set r to 0 (index 0) or handle boundary properly if range is from 1 to N instead of 0 to N-1

        // Calculate and print the answer (difference in prefix sums) for this query range [L, R]
        int ans = P[r + 1] - P[l]; // Corrected index for prefix sum array P (was using 'r' instead of 'r+1')
        cout << ans << endl; // Print the answer for this query range
    }
    return 0; // Proper return statement at the end of main function is always good practice
}