#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// Using a simple vector for the prefix sum instead of a map for better performance.
using PrefixSumVector = vector<ll>;

// Remove unnecessary preprocessor macros and replace them with clean and readable code.

int main() {
    int N; // Number of elements in the array
    cin >> N;
    PrefixSumVector prefixSum(N + 1); // Vector to store the prefix sum
    prefixSum[0] = 0; // Initialize the first element as 0

    // Read the array elements and calculate the prefix sum
    for (int i = 1; i <= N; ++i) {
        ll p;
        cin >> p;
        prefixSum[i] = prefixSum[i - 1] + p; // Accumulate the prefix sum
    }

    // Read the number of queries
    int Q;
    cin >> Q;

    // Process each query by finding the corresponding prefix sum difference
    for (int q = 0; q < Q; ++q) {
        int L, R; // Left and right bounds for the query range
        cin >> L >> R; // Read the query bounds
        
        // Find the indices in the prefixSum vector corresponding to L and R (adding 1 due to 0-based indexing)
        int l = L - 1; // Adjusting for 0-based indexing in the prefixSum vector
        int r = R - 1; // Adjusting for 0-based indexing in the prefixSum vector
        // Check for bounds and handle cases where the index is out of bounds (e.g., L/R are out of array range)
        if (l < 0 || r >= N) {
            cout << "0" << endl; // Output 0 or handle the error appropriately if out of bounds is not allowed.
            continue; // Skip this query or handle it appropriately.
        }
        // Calculate and output the difference in prefix sums for the query range.
        ll ans = prefixSum[r + 1] - prefixSum[l]; // Using r+1 to account for inclusive end in the query range.
        cout << ans << endl; // Output the result for this query.
    }
    return 0; // Return 0 to indicate successful completion of the program.
}