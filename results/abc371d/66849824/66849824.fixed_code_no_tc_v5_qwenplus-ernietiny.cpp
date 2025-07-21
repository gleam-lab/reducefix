#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of queries
    vector<int> X(N); // Array X to store the values of X_i
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Input values of X_i
    }
    
    // Initialize the graph with adjacency list representation
    vector<vector<int>> graph(N + 1); // Graph represented as vector of vectors
    for (int i = 0; i < N; ++i) {
        graph[X[i]].push_back(i); // Connect nodes with indices
    }
    
    // Process each query separately
    int Q; // Number of queries to process
    cin >> Q; // Number of queries to solve
    
    // Calculate the answer for each query
    for (int query : {0, 1, 2, ... Q}) { // Iterate over each query
        int L, R; // Left and Right indices for the query range
        cin >> L >> R; // Input the range of indices for the query
        // Check if the range is within the graph boundaries
        if (L < 0 || R >= N || R < L) { // Handle edge cases and constraints
            cout << "Invalid range" << endl; // Return an error message if invalid range
            continue; // Skip the current query and move on to the next one
        }
        // Calculate the answer for the current query
        int ans = graph[R] - graph[L]; // Calculate the difference between X_r and X_l for the current query range
        cout << ans << endl; // Output the answer for the current query range
    }
    
    return 0; // Return 0 if no errors occur or a positive value if fixed code is correct
}