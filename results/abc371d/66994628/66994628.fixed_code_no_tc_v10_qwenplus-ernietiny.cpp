#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Read the number of patches
    
    // Patch 1: Allocate space for sum array with correct bounds
    int sumSize = n + 1; // Total number of elements in the sum array
    sum[0] = 0; // Initialize the first element of the sum array with zero
    
    // Read patches for x[] and p[] arrays
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // Read patches for x[] array
        sum[i] = sum[i - 1] + p[i]; // Update the sum based on patch values
    }
    
    // Patch 2: Reading the query values correctly
    cin >> q; // Read the number of queries
    while (q--) { // Process each query separately
        int l, r; // Read the left and right boundaries of the query range
        cin >> l >> r; // Read the query boundaries
        // Lower bound should be less than upper bound for correctness
        l = l - n - 1; // Adjust lower bound if necessary
        // Calculate the sum difference between left and right patches
        cout << sum[r - 1] - sum[l - 1] << endl; // Output the desired result
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}