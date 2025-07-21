#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N+1); // Array to store X values
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read X values
    map<int, int> X_to_idx; // Map to store indices of X values
    for (int i = 0; i < N; ++i) X_to_idx[X[i]] = i; // Initialize indices based on X values
    int Q; // Number of queries
    cin >> Q; // Number of queries to answer

    // Fixed code to handle the query case
    for (int query : all(X)){ // For each query value in X
        int left, right; // Left and right boundaries for range querying
        cin >> left >> right; // Input the left and right boundaries of the range to query
        int result = P[right] - P[left]; // Calculate the expected answer for the query range
        cout << result << endl; // Output the expected answer for the query range
        // Add handling for cases where index exceeds bounds, as per requirements
        // if (X_to_idx[query] < N){ // Additional condition for boundary check
        //     // Left boundary should be updated based on current query value in the correct order
        //     left = X_to_idx[query]; // or use another index based on X value for boundary check
        // }
    }
    return 0;
}