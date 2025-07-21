#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Assuming N is the number of patches.
    vector<int> P(N); // Initialize patches array with proper values.
    cin >> P[0]; // Initialize patch value at the first position.

    // ... Code to populate P ...

    int Q; // Number of queries.
    cin >> Q; // Read the number of queries.

    // Initialize pointers for efficient range queries.
    auto it_lower = x_to_ptr.lower_bound(0); // Initialize it to the first element.
    auto it_upper = x_to_ptr.upper_bound(N - 1); // Initialize it to the last element.

    // Fixing algorithm errors:
    for (int q = 0; q < Q; ++q){ // Loop through each query.
        int L, R; // Define query ranges.
        cin >> L >> R; // Read the query ranges.
        // Check if the range is valid by checking bounds.
        if (L < 0 || R >= N || L > R) { // Handle edge cases and constraints.
            cout << "Invalid range." << endl; // Print an error message if range is invalid.
            continue; // Skip this query and move on to the next one.
        }
        // Perform the patch-patch difference calculation.
        int ans = P[R] - P[L]; // Calculate the difference between patches in the query range.
        cout << ans << endl; // Print the result of the difference calculation.
    }

    return 0; // Return 0 to indicate successful completion of the program.
}