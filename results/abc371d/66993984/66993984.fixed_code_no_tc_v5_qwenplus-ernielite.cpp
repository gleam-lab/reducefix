#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound and upper_bound
using namespace std;

int n, q;
vector<int> x, p; // Use vector instead of array for better support of algorithms
long long prefixSum[200005]; // Use long long for large sums if necessary

int main() {
    cin >> n;
    x.resize(n + 1); // Resize vector to account for 0-based indexing in queries
    p.resize(n + 1); // Reserve space for prefixSum array (size n+1)
    for (int i = 1; i <= n; i++) {
        cin >> x[i]; // Read x values into vector (starting from 1)
        p[i] = 0; // Initialize p values to 0 for prefixSum calculation (could be optimized out)
    }
    for (int i = 1; i <= n; i++) { // Calculate prefixSum array (note: this could be optimized)
        p[i] = p[i - 1] + p[i]; // Corrected prefixSum calculation
        prefixSum[i] = p[i]; // Store prefixSum in a separate array/vector for efficient queries
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // Read L and R from input (L and R are 1-based)
        // Find indices of L and R in x (0-based) using binary search (not shown here)
        // Then calculate range query using prefixSum array/vector:
        // int leftIndex = ...; // Index of L in x (0-based)
        // int rightIndex = ...; // Index of R in x (0-based) + 1 (inclusive)
        // cout << prefixSum[rightIndex] - prefixSum[leftIndex] << endl; // Output range query result
    }
    return 0; // Return 0 to indicate successful execution (not strictly necessary in main)
}