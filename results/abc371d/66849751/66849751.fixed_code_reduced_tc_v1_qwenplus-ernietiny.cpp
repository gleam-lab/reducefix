#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N); // Test case input
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read test case inputs

    // Create a map to store the indices of elements in X array
    map<int, int> x_to_idx;
    for (int i = 0; i < N; ++i) x_to_idx[X[i]] = i; // Build the index map

    // Calculate the sum of patches (patches are represented as integers)
    int patches = 0;
    for (int i = 1; i <= N; ++i) { // Iterate over all test cases
        int patch_start, patch_end; // Patch values for each test case
        cin >> patch_start >> patch_end; // Read the patch values for each test case
        patches += X[patch_end] - X[patch_start]; // Calculate the sum of patches for the current test case
    }

    // Calculate the final answer based on the sum of patches
    cout << patches << endl; // Output the final answer

    return 0;
}