#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N); // Test case input
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read test case inputs

    // Initialize P array with the correct value for the first element
    P[0] = 999969310; // Assuming the first element is always present and has a value
    // ... Additional code to fill P[] with actual data follows ...

    int Q; // Number of queries
    cin >> Q; // Number of queries to be answered
    
    // Initialize pointers for binary search
    auto X_l = lower_bound(X.begin(), X.end(), 730002498); // Assuming the queries are sorted by X values
    auto X_r = upper_bound(X.begin(), X.end(), 999997297); // Assuming the queries are sorted by X values
    if (X_l == X.end()) X_l = N; // Handle edge case where no element matches the query value
    if (X_r == X.end()) X_r = N - 1; // Handle edge case where query value is too large for existing element range

    // Binary search queries based on the query range and current range for P[]
    for (int q = 0; q < Q; ++q){ // Handle multiple queries separately
        int L, R; // Query ranges for binary search
        cin >> L >> R; // Read query ranges for binary search
        int ans = P[r] - P[l]; // Calculate the answer based on binary search results
        cout << ans << endl; // Output the answer for the query range
    }
}