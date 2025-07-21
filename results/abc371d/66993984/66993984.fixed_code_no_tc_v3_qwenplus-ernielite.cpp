#include <iostream>
#include <vector>
#include <algorithm> // For lower_bound and upper_bound
using namespace std;

int main() {
    int n, q;
    cin >> n; // Number of elements in x and p
    vector<int> x(n), p(n); // Declare vectors instead of arrays for better performance and readability
    vector<int> prefixSumP(n + 1); // Use a vector to store prefix sum of p[] efficiently
    
    // Read and store values in x and p vectors
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        // Calculate prefix sum of p[] and store in prefixSumP vector
        prefixSumP[i + 1] = prefixSumP[i] + p[i]; 
    }
    
    cin >> q; // Number of queries
    while (q--) {
        int L, R;
        cin >> L >> R; // Read L and R for each query
        // Perform binary search to find indices for L and R (assuming x is sorted)
        auto cIter = lower_bound(x.begin(), x.end(), L); // cIter points to first element >= L
        auto dIter = upper_bound(x.begin(), x.end(), R); // dIter points to first element > R (not inclusive)
        // Calculate the difference in prefix sums using cIter and dIter indices (dIter - 1 because upper_bound is exclusive)
        if (cIter != x.begin()) { // Check if cIter is not the beginning to avoid out-of-bounds access
            int c = distance(x.begin(), cIter); // Get index of cIter relative to x.begin()
            int d = distance(x.begin(), dIter) - 1; // Get index of dIter relative to x.begin() - 1 since upper_bound is exclusive
            cout << prefixSumP[d] - prefixSumP[c] << endl; // Output the difference in prefix sums for the query range [L, R)
        } else {
            // Handle edge case where L is the smallest value in x (no preceding elements)
            cout << "No range found" << endl; // Or any other appropriate message/action based on your requirements for this case
        }
    }
    return 0; // Good practice to return 0 from main function indicating successful execution
}