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

    // Calculate the total patches (X_i minus X[l] and X_r)
    int total_patches = N - X[0]; // X[N] is the last element in all cases

    // Process each test case separately
    for (int Q = 1; Q <= N; ++Q){ // Q represents the number of queries
        int L, R, patch_sum; // L and R are the left and right patches, respectively
        cin >> L >> R; // Read the left and right patches
        // Calculate the patch sum as the sum of patches minus total patches
        patch_sum = total_patches - X[R]; // This assumes X[R] is always valid for all queries
        cout << patch_sum << endl; // Output the answer for this query
    }

    return 0; // Return 0 to indicate successful completion of the program
}