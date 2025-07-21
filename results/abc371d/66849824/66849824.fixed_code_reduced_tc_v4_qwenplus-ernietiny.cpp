#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N); // Test case input
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read test case inputs

    // Initialize the graph with adjacency list representation
    vector<vector<int>> graph(N); // Graph adjacency list representation
    for (int i = 0; i < N; ++i) cin >> graph[X[i]]; // Read edges for each test case

    // Compute the number of repaired values (total removal) and output accordingly
    int repaired = 0; // Number of repaired values
    for (int Q = 1; Q <= N; ++Q){ // Iterate through each test case
        int L, R, l, r; // Input elements for repair queries
        cin >> L >> R; // Input repair query elements
        if (L < R){ // Ensure correct range for query elements
            auto x_to_ptr_upperBound = graph.upper_bound(L); // Upper bound index of target element in the range
            auto x_to_ptr_lowerBound = graph.lower_bound(R); // Lower bound index of target element in the range
            if (x_to_ptr_upperBound == end(graph) || x_to_ptr_lowerBound == end(graph)) continue; // Handle edge cases if graph is empty or contains no elements in the range
            int target = (*x_to_ptr_lowerBound).second; // Target element index in the range
            int repairValue = P[target] - graph[target]; // Compute the repair value for the query element
            repaired += repairValue; // Add the repaired value to the total count
        }
        cout << repaired << endl; // Output the repaired value count for the current test case
    }
    return 0;
}