#include <bits/stdc++.h>
using namespace std;

int n, q;
int x[200005]; // No need for p and sum here, as they are not used in the corrected code

// Since we are dealing with queries, we will need a data structure to efficiently calculate the sum.
// A segment tree or a prefix sum array would be appropriate. Here, we will use a prefix sum array.
int prefixSum[200005]; // Initialize prefixSum to keep track of the cumulative sum of elements in x[]

// Function to calculate the prefix sum
void calculatePrefixSum(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    cin >> n; // Read the number of elements in x[]
    for (int i = 0; i < n; i++) { // Read the elements into x[]
        cin >> x[i];
    }
    // Calculate the prefix sum of x[]
    calculatePrefixSum(x, n);
    
    cin >> q; // Read the number of queries
    while (q--) { // Process each query
        int L, R; // Read the query range [L, R]
        cin >> L >> R;
        // Since we have a prefix sum array, we can efficiently find the sum of elements in range [L, R]
        // by subtracting the prefix sum at L-1 from the prefix sum at R. However, since prefixSum is 1-indexed, we need to adjust L and R.
        int sumInRange = prefixSum[R] - (L > 0 ? prefixSum[L - 1] : 0); // Check for L == 1 to avoid index out of bounds for negative L.
        cout << sumInRange << endl; // Output the result for each query
    }
    return 0; // Good practice to include a return statement in main() even if it's not strictly necessary in C++ programs.
}