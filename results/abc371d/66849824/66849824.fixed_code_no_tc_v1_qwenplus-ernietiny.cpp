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
    
    // Fix the algorithm errors and implement the solution accordingly
    // ... (details to be filled in) ...
    
    return 0; // Return the answer for the given Q
}