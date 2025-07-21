#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array
    
    // Create a map to store the sum of elements in each range
    map<int, int> sumRange;
    for (int i = 1; i <= n; ++i) {
        sumRange[i] = sum[i - 1]; // Initialize the sum of elements in each range with the previous sum
    }
    
    // Read the queries
    while (true) {
        int L, R; // Query range boundaries
        cin >> L >> R; // Read the query range boundaries
        
        // Find the difference between the two ranges' indices in the map
        int diff = lower_bound(sumRange.begin(), sumRange.end(), L) - sumRange.begin(); // Lower bound index
        int complementDiff = upper_bound(sumRange.begin(), sumRange.end(), R) - sumRange.begin(); // Upper bound index
        
        // Calculate the difference between the two ranges' sums and output it
        cout << sumRange[R - diff] - sumRange[complementDiff] << endl; // Output the difference between the ranges' sums
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}