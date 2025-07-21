#include <bits/stdc++.h>

using namespace std;

// Utility function to convert number of elements in a vector to their index in the P vector
int index(const vector<int>& X, int n) {
    return (int)lower_bound(all(X), n);
}

int main(){
    int N;
    cin >> N; // Number of queries
    vector<int> P(N + 1); // Initialize P vector with default value for testing purposes
    cin >> P[0]; // Assume P[0] is zero for now
    for (int i = 1; i <= N; ++i) {
        cin >> P[i]; // Read the elements from input for the queries
    }
    
    // Assuming that x_to_ptr stores the indices of elements in sorted order
    // For each query, find the left and right indices of X_i in sorted order and calculate the difference
    for (int Q = 1; Q <= QCount; ++Q){ // Assuming QCount is the number of queries
        int L, R; // Query left and right indices
        cin >> L >> R; // Read the indices for the current query
        auto X_l = x_to_ptr.lower_bound(L); // Find the index of X_i in sorted order
        auto X_r = index(P, R); // Find the index of X_i in the actual P vector
        int ans = P[X_r] - P[X_l]; // Calculate the difference between the expected and actual value
        cout << ans << endl; // Output the result
    }
    return 0; // Return 0 to indicate successful completion of the program
}