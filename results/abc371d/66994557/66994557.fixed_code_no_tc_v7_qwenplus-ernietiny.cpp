#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Number of patches
    
    // Initialize patch counts and sums
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // Patch counts
        sum[i] = x[i]; // Patch sums
    }
    
    // Process queries
    while (q--) {
        int L, R; // Patch locations to be queried
        cin >> L >> R; // Query locations
        
        // Find the range of patches within the given bounds
        int l = lower_bound(x + 1, x + n + 1, L) - x - 1; // Adjust for boundary conditions
        int r = upper_bound(x + 1, x + n + 1, R) - x - 1; // Adjust for boundary conditions
        
        // Calculate the difference between the patch sums at the two bounds
        cout << sum[r] - sum[l] << endl; // Output the difference
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}