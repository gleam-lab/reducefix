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

    // Calculate the sum of patches (patches are represented as patches + patch value)
    int patches_sum = 0;
    for (int Q = 1; Q <= N; ++Q){ // Process Q test cases
        int L, R; // Left and Right bounds of the query interval
        cin >> L >> R; // Read query interval bounds
        int query_patch = X[R] - X[L]; // Calculate the patch value of the query interval
        patches_sum += query_patch; // Add the patch value to the total sum
        // Check if the patch is negative or not to avoid division by zero
        if (query_patch < 0) patches_sum = -patches_sum; // Replace negative value with positive if necessary
        // Print the answer as required (assuming it's a positive number)
        cout << patches_sum << endl; // The code for handling negative patches should be included here if needed
    }
    return 0; // Return 0 to indicate successful completion of the program
}