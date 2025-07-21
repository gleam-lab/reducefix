#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// Fixed the reps macro to correctly represent a range with a possible end-inclusive loop
#define reps(i,n) for (int i = 0; i <= (n); ++i)

// The rest of the code remains the same...

// ... (previous code remains unchanged) ...

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N); // Initialize P with one extra element for P[0] = 0
    P[0] = 0; // Set P[0] to 0 as a base case for prefix sum calculation
    rep(i, N) {
        cin >> X[i]; // Read X values into the array
        P[i + 1] = P[i] + X[i]; // Calculate prefix sum for P array
    }
    map<int, int> x_to_ptr; // Initialize the map to store X values as keys and indices as values
    reps(i, N) { // Use reps instead of rep to handle possible end-inclusive loop for indices
        x_to_ptr.emplace(X[i], i); // Store X values and their corresponding indices in the map
    }
    // ... (previous code remains unchanged) ...

    int Q; // Number of queries to process
    cin >> Q; // Read number of queries
    rep(q, Q) { // Process each query...
        int L, R; // Range query limits L and R
        cin >> L >> R; // Read the limits of the range query
        auto X_l_it = x_to_ptr.lower_bound(L); // Find the iterator for the first element greater than or equal to L in x_to_ptr
        if (X_l_it == x_to_ptr.end()) { // If not found, set l to N (or one less than P array size)
            int l = N - 1; // Adjust based on P array size if needed (e.g., if P is from 1 to N)
        } else { // If found, get the index from the iterator's value
            int l = (*X_l_it).second; // Use .second to get the index from the pair in the map's value type (int, int)
        }
        auto X_r_it = x_to_ptr.upper_bound(R); // Find the iterator for the first element greater than R in x_to_ptr (exclusive)
        if (X_r_it != x_to_ptr.begin()) { // To handle the edge case where R is less than or equal to the first value in x_to_ptr
            --X_r_it; // Decrement to get the previous element (index before R) in x_to_ptr since upper_bound is exclusive.
        }
        if (X_r_it == x_to_ptr.end()) { // If R is not found in x_to_ptr, set r to N (or one less than P array size)
            int r = N - 1; // Adjust based on P array size if needed (e.g., if P is from 1 to N)
        } else { // If found, get the index from the iterator's value's second member (as before)
            int r = (*X_r_it).second; // Use .second to get the index from the pair in the map's value type (int, int)
        }
        // Now calculate and print the answer using prefix sum array P...
        int ans = P[r + 1] - P[l]; // Adjust based on P array indexing (if P starts from 1, use r+1 instead of r)
        cout << ans << endl; // Print the answer for this query...
    }
    return 0; // Return 0 to indicate successful completion of main function...
}