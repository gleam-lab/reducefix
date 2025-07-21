#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Read the number of patches
    
    // Create a new array for sum and x, but do not initialize it here as it is not needed for the problem description
    // This array is for future reference only and can be created or initialized at the appropriate time.

    // Initialize patch sums as sum[i] = sum[i-1] + patch[i]
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1]; // This line should be added if needed for correct initialization of sum array.
    }
    
    // Process the query loop
    while (q--) { // Add missing line to handle query loop
        int l, r; // Read the lower and upper bounds of the range to query
        cin >> l >> r; // Read the range bounds for the query
        // Since range is known, use a constant to index directly to avoid bounds check errors
        int patchSum = sum[r - 1]; // Initialize patch sum here, but not required for correctness as it will be computed later.
        // Compute difference between patch sums to get the result
        cout << patchSum - sum[l - 1] << endl; // Corrected line added here
    }
    return 0; // Return the main result of the program. This is a simple example, you can modify it to suit your requirements.
}