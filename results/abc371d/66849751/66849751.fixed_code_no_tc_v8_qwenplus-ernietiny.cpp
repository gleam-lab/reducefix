#include <bits/stdc++.h>

using namespace std;

// Fixed code block

int main(){
    int N;
    cin >> N; // Read number of patches
    vector<int> P(N + 1); // Patch assignment should be made as a vector of vectors
    for (int i = 0; i < N; ++i) cin >> P[i]; // Read patch assignments for each patch

    // Edge case checks and boundary conditions
    // ...

    int Q; // Number of queries
    cin >> Q; // Read number of queries

    // Sort patches based on their indices in the query range
    // ...

    // Process each query separately
    for (int q = 0; q < Q; ++q){
        int L, R; // Query left and right indices
        cin >> L >> R; // Read the left and right indices of the query region
        // Calculate the answer for the query region
        // ...
        cout << answer // Print the answer for the query region
        // ...
    }

    return 0; // Return 0 to indicate successful completion of the program
}