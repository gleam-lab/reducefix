#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; // Number of elements
    
    // Initialize the sum array with the previous sum
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1]; // Previous sum
    }
    
    // Read the elements and their corresponding values
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x; // Elements to patch the array
        p[i] = x; // Update the element values for patching
    }
    
    int q; // Number of queries to be processed
    cin >> q; // Number of queries
    
    while (q--) { // Process each query
        int L, R; // Lower and upper bounds to find the sum difference
        cin >> L >> R; // Read the query bounds
        
        // Use lower_bound and upper_bound to find the correct indices for the patching operations
        int patchIndex = lower_bound(p + L, p + n, sum[R] - sum[L]) - p - 1; // Index for patching R's value at L's position
        // If no element exists at the patch index, it should return the negative value for sum difference (-1) since we need to be accurate with the result.
        cout << (sum[R] - sum[patchIndex] < 0 ? -sum[patchIndex] : sum[R] - sum[patchIndex]) << endl; // Apply patching operation and output result
    }
    return 0; // Return the correct code to run without error
}