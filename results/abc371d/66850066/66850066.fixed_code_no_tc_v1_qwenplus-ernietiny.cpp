#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of queries
    vector<int> X(N); // Array X to store the values of X
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read values of X
    }
    
    // Initialize P array with the initial value of P[0] set to 0
    vector<ll> P(N + 1);
    P[0] = 0; // Initialize P array with the initial value of P[0]
    
    // Process each query
    for (int Q = 1; Q <= QCount; ++Q) { // Assuming QCount is the number of queries
        int L, R; // L and R are the indices of the left and right bounds respectively
        cin >> L >> R; // Read the left and right bounds for each query
        // Check if the index is within bounds and if the corresponding value exists in P array
        if (X[L] != X[R]) { // If the index is out of bounds or the corresponding value does not exist in P array
            cout << "No solution" << endl; // Return "No solution" if no solution exists
            continue; // Skip this query and continue to the next one
        }
        // Calculate the difference between P[R] and P[L] and print it
        cout << P[R] - P[L] << endl; // Replace P[R] with the actual value stored in P array for better performance
    }
    return 0; // Return 0 to indicate successful completion of the program
}