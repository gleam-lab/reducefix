#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements in the array
    
    // Create a map to store the sum of each element and its index
    map<int, int> sumMap;
    
    // Populate the map with the given elements
    for (int i = 1; i <= n; ++i) {
        cin >> x[i]; // Elements in the array x
        sumMap[x[i]] = i; // Store the index of each element in the map
    }
    
    // Read the query size and range
    int q;
    cin >> q; // Number of queries
    
    // Initialize variables for query processing
    long long querySum = 0; // Query sum to be calculated
    long long previousSum = 0; // Previous sum encountered during query processing
    int currentIndex = 0; // Current index for querying the range
    
    // Process each query separately
    while (q--) {
        int L, R; // Query range in the form of lower and upper indices
        cin >> L >> R; // Query range in the array x
        
        // Calculate the difference between current sum and previous sum for the range
        querySum = sumMap[R] - sumMap[L - 1]; // Using lower_bound to find the correct index in the map
        
        // Output the result of the query sum minus previous sum as it is expected to be negative in some cases
        cout << querySum - previousSum << endl; // Negative numbers are expected to be returned by some algorithms
        previousSum = querySum; // Update previous sum for next query processing
    }
    
    return 0; // Return 0 to indicate successful completion of the program
}