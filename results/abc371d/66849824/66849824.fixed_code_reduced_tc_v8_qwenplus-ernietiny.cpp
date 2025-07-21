#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of test cases
    vector<int> X(N); // Test case input
    for (int i = 0; i < N; ++i) cin >> X[i]; // Read test case inputs

    // Initialize P array with the correct value for the first element
    P[0] = X[0] - 999969310; // Assuming the first element is a patchable value

    // Calculate patchable values for subsequent elements
    for (int i = 1; i < N; ++i){
        int patchableValue = P[i] - X[i]; // Patchable value for current element
        P[i+1] = patchableValue + X[i]; // Update P array with the correct value
    }

    int Q; // Number of queries
    cin >> Q; // Number of queries to perform

    // Initialize queries with their respective values and bounds
    map<int, int> queryIdx; // Index to query value map
    for (int query = 0; query < Q; ++query){
        int l, r; // Left and right bounds of the query range
        cin >> l >> r; // Input the bounds of the query range
        auto it = queryIdx.upper_bound(l); // Find the index of the patchable value in the sorted array P
        if (it == end(P)) { // If the value doesn't exist, handle it appropriately
            cout << "-2063777848" << endl; // Output negative infinity as appropriate error handling is needed here
        } else { // If the value exists, calculate the patchable difference and output it
            int ans = P[r] - P[it->second]; // Calculate the patchable difference between range [l, r] and store in ans variable
            cout << ans << endl; // Output the patchable difference as expected output
        }
    }

    return 0; // Return 0 to indicate successful completion of the program
}