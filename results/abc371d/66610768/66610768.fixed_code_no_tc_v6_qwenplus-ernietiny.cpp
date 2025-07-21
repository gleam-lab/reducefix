#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n; // Number of elements in vector a
    vector<int> a(n + 1); // Assuming a is initialized here
    
    // Read values from the input
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // Elements from vector a
    }
    
    // Fix the algorithm here
    // ... Additional code to fix the algorithm ...
    
    // Read more values from the input for testing purposes
    cin >> m; // Number of subsequent input lines
    
    while (m--) { // Process each subsequent input line
        int l, r; // Elements to compare and calculate difference
        cin >> l >> r; // Elements to compare against the current range
        
        // Fix the range bounds here, considering the size of vector a
        // For example, if a is an array of size N+1, we need to adjust the range accordingly
        auto lower_bound = lower_bound(a.begin() + 1, a.end(), l); // Adjust bounds if necessary
        auto upper_bound = upper_bound(a.begin(), a.end(), r); // Adjust bounds if necessary
        
        // Calculate difference based on the range bounds and element indices
        int i = lower_bound - a.begin(); // Calculate index for comparison
        int j = upper_bound - a.begin(); // Calculate difference if range is narrower than vector size
        
        // Output the difference if range is narrower than vector size or if it's larger than vector size
        if (r < n || j >= n) { // Handle edge cases here if necessary
            cout << (c[n] - c[i - 1]) << endl; // Assuming c[] is the difference array
        } else { // Otherwise, calculate and output the difference as required
            cout << (c[j - 1] - c[i - 1]) << endl; // Calculate and output the difference here
        }
    }
    return 0; // Return 0 to indicate successful completion of the program
}