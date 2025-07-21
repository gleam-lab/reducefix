#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Assuming N is the number of elements in P and X arrays
    vector<int> P(N+1), X(N);
    P[0] = 0; // Initialize P array with 0 for simplicity

    // Read the elements in P and X array
    rep(i, N) cin >> P[i]; // Assuming P[i] represents the patch value for X[i]
    rep(i, N) cin >> X[i]; // Similarly for X array

    // Fix the code to handle the query cases
    int Q; // Number of queries to be processed
    cin >> Q; // Read the number of queries

    // Sort X array based on patch values in ascending order
    sort(X.begin(), X.end());

    // Process each query case
    for (int query = 0; query < Q; ++query){
        int L, R; // Query locations L and R in sorted X array
        cin >> L >> R; // Read the query locations
        // Find the correct patch value range based on query location
        int l = L - 1, r = R - 1; // Initialize left and right pointers to range from index 0 to N-1
        while (l >= 0 && X[l] <= L) l--; // Move left pointer to the correct range index
        while (r < N && X[r] >= R) r++; // Move right pointer to the correct range end index
        // Calculate the answer for the query location
        int ans = P[r] - P[l]; // Corrected code to calculate the answer for the query location based on range bounds
        cout << ans << endl; // Output the answer for the query case
    }

    return 0; // Return 0 to indicate successful completion of the program
}