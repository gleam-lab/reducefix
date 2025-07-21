#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N); // Test case input
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read test case inputs

    // Create a map to store the indices of X elements
    map<int, int> x_to_idx; // {index, value} pair for easier access
    for (int i = 0; i < N; ++i) x_to_idx[X[i]] = i; // Assign indices to X elements

    // Calculate the sum of patches (patches are represented as patches + patch value)
    int sum_patches = 0; // Initialize sum to patch value count
    for (int Q = 1; Q <= N; ++Q){ // Process Q test cases
        int L, R, l, r; // Test case inputs for L and R
        cin >> L >> R; // Read test case inputs L and R
        int patch_value = X[R]; // Patch value for current query
        auto it = x_to_idx.lower_bound(L); // Find the index of the leftmost element that satisfies query
        if (it == end(x_to_idx)) { // If the element is not found, use the entire range [0, N)
            sum_patches += patch_value - N; // Compute the sum of patches that do not satisfy the query
        } else { // If the element is found, update the sum accordingly
            sum_patches += patch_value - (*it); // Calculate the sum of patches that satisfy the query
        }
        cout << sum_patches << endl; // Output the calculated sum of patches
    }
}