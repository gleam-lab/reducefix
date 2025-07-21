#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N); // Test case input
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read test case inputs

    // Create a map to store the indices of elements in X array
    map<int, int> x_to_idx; // {X[i]: index}
    for (int i = 0; i < N; ++i) x_to_idx[X[i]] = i; // Assign indices to elements

    // Calculate the number of patches (edges) in the graph
    int patches = N - 1; // Each patch represents the difference between two adjacent elements

    // Initialize the patch value to the current element's value
    int patch_value = X[N - 1]; // Example value for the last element

    // Iterate over each query range (Q) and calculate the answer
    for (int Q = 1; Q <= N; ++Q){ // Number of queries should be less than or equal to the number of elements
        int L, R; // Query range for each patch
        cin >> L >> R; // Read the query range for each patch
        // Calculate the patch value based on the current element and its adjacent patches
        int patch_sum = patch_value - (X[L] - X[R] + patches); // Calculate the sum of patches for the current patch
        cout << patch_sum << endl; // Output the answer for the current query range
    }
}