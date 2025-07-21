#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // Number of patches
    
    // Patch 1: Read the patches x[] and their corresponding values p[]
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // Patch value x[i]
        p[i] = x[i]; // Patch value stored in sum array
    }
    
    // ... Other code for patch processing ...
    
    // Patch 2: The logic for finding the left and right indices based on lower and upper bounds
    int L, R; // Assuming L is the lower bound and R is the upper bound for finding the range of sum values to be printed
    cin >> L >> R; // Read the range of sum values to be printed
    
    // Calculate the difference between sum[r-1] and sum[l-1] for the current patch query
    int difference = sum[R - 1] - sum[L - 1]; // This should be printed if querying range is valid
    
    // Print the corrected value
    cout << difference << endl; // Output the corrected value if range is valid
    
    return 0; // Return 0 to indicate successful completion of the program
}