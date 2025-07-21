#include <bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
// Use a vector instead of a map for efficient prefix sum computation
vector<int> prefixSum(200005);

int main() {
    cin >> n;
    // Fill the array x with input values
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    // Compute the prefix sum of p and store it in prefixSum vector
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefixSum[i] = prefixSum[i - 1] + p[i]; // Use prefixSum instead of sum map
    }
    
    cin >> q;
    // Use a separate function or method to handle the query processing
    processQueries(q, x, prefixSum); // Assuming processQueries is a separate function that handles queries
    return 0;
}

// Function to process queries given a set of queries L and R
void processQueries(int numQueries, const int* x, const vector<int>& prefixSum) {
    while (numQueries--) {
        int L, R;
        cin >> L >> R; // Read the query range L and R from input
        // Find the indices of L and R in the sorted array x using binary search
        auto itL = lower_bound(x + 1, x + n + 1, L) - x; // c is the index of L in x (inclusive)
        auto itR = upper_bound(x + 1, x + n + 1, R) - x - 1; // d is the index of R in x (exclusive)
        // Calculate the range sum query using prefix sum array
        cout << prefixSum[itR] - prefixSum[itL] << endl; // Output the result of the range sum query
    }
}