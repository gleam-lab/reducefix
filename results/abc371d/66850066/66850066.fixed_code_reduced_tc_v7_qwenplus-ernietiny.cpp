#include <bits/stdc++.h>

using namespace std;

// Utility function to convert number of elements in a vector to the corresponding index
int to_idx(vector<int>& elems, int N) {
    return lower_bound(all(elems), N) - 1;
}

int main(){
    int N;
    cin >> N; // Number of elements in the input list P
    vector<int> P(N + 1); // Preallocate memory for the input list
    cin >> P[0]; // Initialize first element as zero if not specified in the input

    // Input elements P[] into the vector
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Fix the current input and get X[] sorted in descending order (as requested)
    for (int i = 0; i < N; ++i) {
        int x_value = X[i]; // Current value of X[] element
        // Check if we need to shift left to reach the given index range [L, R]
        int shift = max(0, to_idx(X, i+1) - to_idx(P, x_value)); // Shift for index comparison
        P[i + shift] -= P[i]; // Subtract current element from the shifted index
    }

    // Answer based on the sorted indices
    int Q; // Number of queries
    cin >> Q; // Number of queries to answer
    for (int query : all(Q)) { // Iterate over each query separately
        int L, R; // Lower and upper bounds of X[] range to be considered for querying
        cin >> L >> R; // Input the lower and upper bounds of X[] range for querying
        // Calculate the expected answer based on the sorted indices and range bounds
        int expected_answer = P[R] - P[L]; // Expected answer for the query range [L, R]
        cout << expected_answer << endl; // Output the expected answer for the query range [L, R]
    }
}