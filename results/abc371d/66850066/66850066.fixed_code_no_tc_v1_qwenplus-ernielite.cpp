#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// Corrected macro definitions for clarity and consistency
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, n) for (int i = 1; i <= (n); ++i) // Changed to start from 1 if necessary
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define YES(b) cout << ((b) ? "YES" : "NO") << endl

// Corrected the direction of dx and dy arrays for proper 4-directional movement
int dx[] = {1, -1, 0, 0}; // Horizontal movement
int dy[] = {0, 0, 1, -1}; // Vertical movement

int main() {
    int N; // Number of elements in the array X and P
    cin >> N;
    vector<ll> P(N + 1), X(N); // P is a prefix sum array, X is the input array
    P[0] = 0; // Initialize prefix sum at index 0 with 0
    rep(i, N) {
        cin >> X[i]; // Read values into X array
        P[i + 1] = P[i] + X[i]; // Calculate prefix sum for P array
    }
    // Create a map from X values to their indices in the X array
    map<int, int> x_to_ptr;
    for (int i = 0; i < N; ++i) { // Use regular loop to populate the map for clarity.
        x_to_ptr.insert({X[i], i}); // Insert key-value pair in the map with X[i] as key and i as value.
    }
    // Now we can use x_to_ptr to quickly find the indices for a given value in X.

    // Read the number of queries Q and process them one by one.
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) { // Use regular loop for clarity.
        int L, R; // Left and right bounds for the query range.
        cin >> L >> R; // Read the query bounds.
        // Find the indices l and r corresponding to L and R in the X array using x_to_ptr.
        auto itL = x_to_ptr.lower_bound(L); // Iterate to the first element >= L in x_to_ptr.
        auto itR = x_to_ptr.upper_bound(R); // Iterate to the first element > R in x_to_ptr.
        // If L is not found, it means there are no elements in X >= L, so l should be N (out of bounds).
        // If R is not found, it means we've reached the end of X array, so r should be N-1 (one less than the array size).
        int l = (itL == x_to_ptr.end()) ? N : itL->second; // Use itL->second to get the index.
        int r = (itR == x_to_ptr.end()) ? N - 1 : itR->second - 1; // Subtract 1 because we want the index before the end of X array.
        // Now we have l and r indices for our query range, calculate the prefix sum difference and print it.
        ll ans = P[r + 1] - P[l]; // Add +1 because we are using prefix sum array P which includes all elements up to N+1th index.
        cout << ans << endl; // Print the result for this query.
    }
    return 0; // Standard main function return statement.
}