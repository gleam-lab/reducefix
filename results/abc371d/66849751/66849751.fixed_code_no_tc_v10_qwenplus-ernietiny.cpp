#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Assume N is always a valid number
    vector<int> P(N+1), X(N); // Assuming X[i] are already defined and valid
    P[0] = 0; // Initialize P vector with 0 for simplicity

    // Read the X values from the input
    rep(i, N) cin >> X[i];

    // Process the P vector to calculate the modified X values
    rep(i, N) P[i+1] = P[i] + X[i]; // Assuming X[i] are already sorted in ascending order

    // Fix the algorithm errors
    // ... (fix the code according to the provided requirements) ...

    int Q; // Number of queries
    cin >> Q; // Read the number of queries

    // Process each query separately
    while (Q--) {
        int L, R; // Query indices for X_l and X_r
        cin >> L >> R; // Read the indices for the queries
        // ... (fix the code to calculate the modified X values for each query) ...
        // Output the result of the query
        cout << P[R] - P[L] << endl; // Calculate and output the modified X value for each query
    }

    return 0; // Return 0 to indicate successful completion of the program
}