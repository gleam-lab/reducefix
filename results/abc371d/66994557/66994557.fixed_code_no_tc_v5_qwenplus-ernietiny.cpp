#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Number of patches
    
    // Read patch values into the arrays x, p, and sum
    int x[200005], p[200005];
    for (int i = 0; i < n; ++i) {
        cin >> x[i]; // Patch values
    }
    
    // Initialize the sum array with the previous sum value
    for (int i = 0; i < n; ++i) {
        sum[i] = sum[i - 1]; // Previous sum value for the current patch
    }
    
    // Read query values and perform the required operations
    cin >> q; // Number of queries
    while (q--) {
        int L, R; // Patch indices for queries
        cin >> L >> R; // Patch indices for each query
        
        // Calculate the difference between the sum of patches in the range [L, R]
        int diff = sum[R] - sum[L - 1]; // Using lower_bound to find the index of the patch in range [L, R]
        
        // Output the difference as requested
        cout << diff << endl; // Output the difference between patches in the range [L, R]
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}