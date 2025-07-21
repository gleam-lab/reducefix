#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// Fixed the reps macro to correctly iterate up to N-1
#define rep(i, n) for (int i = 0; i < (n); ++i)

// The rest of the code remains the same...

// ... (Previous code remains unchanged until the main function)

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N); // Initialize the vectors as before
    P[0] = 0; // Initialize the prefix sum array with 0 at index 0

    // Read the elements of X and calculate the prefix sums P[]
    rep(i, N) {
        cin >> X[i];
        P[i + 1] = P[i] + X[i]; // Calculate prefix sum for X[]
    }

    // Create a map from X values to their indices (pointers are not needed here)
    map<int, int> x_to_index; // Use a map to store X values as keys and their indices as values
    rep(i, N) {
        x_to_index[X[i]] = i; // Store the mapping
    }

    // Query processing loop starts here...
    int Q;
    cin >> Q; // Read the number of queries
    while (Q--) { // Use a while loop to process multiple queries if needed (depends on the problem statement)
        int L, R; // Define L and R for each query
        cin >> L >> R; // Read the query range [L, R]
        auto X_l_it = x_to_index.lower_bound(L); // Find the iterator for the lower bound of L in x_to_index
        auto X_r_it = x_to_index.upper_bound(R); // Find the iterator for the upper bound of R in x_to_index
        // Note: If L or R is not found in x_to_index, X_l_it or X_r_it will be equal to x_to_index.end() respectively.
        // In this case, we set l and r to N to handle such cases (assuming N+1 is the size of P)
        int l = X_l_it == x_to_index.end() ? N : X_l_it->second; // Get the index for L if it's not found, otherwise get it from the map entry
        int r = X_r_it != x_to_index.begin() ? (X_r_it - 1)->second : N; // Get the index for R-1 if it's not the first element, otherwise set it to N (same as above)
        // Note: We subtract 1 from X_r_it because we want the index before the upper bound (inclusive). If R is not found, we treat it as if it's at the end of the array.
        // Calculate and print the answer for the current query range [l, r] (inclusive)
        int ans = P[r + 1] - P[l]; // Use r+1 because we want to include the element at R in the prefix sum (since P is 1-indexed)
        cout << ans << endl; // Print the answer for this query
    }
    return 0; // Don't forget to return 0 to indicate successful execution!
}