#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Number of elements in x array
    
    // Read elements from x array
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // No additional comments needed here
    }
    
    // Process and calculate sum for each query range
    while (q--) {
        int l, r; // Query ranges for sum calculation
        cin >> l >> r; // Input query ranges in increasing order
        
        // Get the range's indices starting from the lower boundary
        int left_idx = lower_bound(x + 1, x + n + 1, l) - x - 1; // Use 'upper_bound' instead of 'lower_bound' to avoid duplicates
        int right_idx = upper_bound(x + 1, x + n + 1, r) - x - 1; // Also, ensure it doesn't exceed the range size
        
        // Calculate the difference between sum for the left and right ranges
        cout << sum[right_idx - sum[left_idx] - 1] << endl; // Adjust index accordingly to get correct difference between sum ranges
    }
    return 0; // End of the program
}