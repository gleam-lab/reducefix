#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Number of patches
    
    // Read patch values into respective arrays
    vector<int> patches(n);
    for (int i = 0; i < n; ++i) {
        cin >> patches[i];
    }
    
    // Initialize sum array with previous sum values
    vector<int> sum(n + 1);
    for (int i = 0; i <= n; ++i) {
        sum[i] = sum[i - 1]; // Previous sum value for current patch
    }
    
    // Process queries based on the given range and boundaries
    while (q--) {
        int L, R; // Range and corresponding range boundary
        cin >> L >> R; // Range and boundary values
        
        // Find the left and right indices of the patch within the range
        int l = lower_bound(patches.begin(), patches.end(), L) - patches.begin(); // Lower index for patch L
        int r = upper_bound(patches.begin(), patches.end(), R) - patches.end(); // Upper index for patch R
        
        // Calculate the difference between the sum of patches in the range
        // This is the correct way to calculate the sum of patches outside the range, as it considers the previous sum values for each patch
        cout << sum[r] - sum[l] << endl; // Output the desired result
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}