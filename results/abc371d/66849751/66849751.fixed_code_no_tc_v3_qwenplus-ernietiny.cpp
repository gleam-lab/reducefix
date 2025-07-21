#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // Number of nodes
    vector<int> P(N+1); // Pre-patched code: P[0] = 0
    rep(i, N) cin >> P[i]; // Pre-patched code: Read node values

    // Create a map to store the indices of nodes with their respective pointers
    map<int, int> x_to_ptr; // Corrected code: using x_to_ptr instead of x_to_ptr.size()
    for (int i = 0; i < N; ++i) {
        x_to_ptr[P[i]] = i; // Corrected code: Assign indices to nodes
    }

    int Q; // Number of queries
    cin >> Q; // Read the number of queries

    // Process each query separately
    for (int query : {0, 1, 2, ... Q}) {
        int L, R; // Left and Right bounds for the query range
        cin >> L >> R; // Read the left and right bounds for the query range
        // Corrected code: Use lower_bound and upper_bound to find the correct indices
        auto X_l = x_to_ptr.lower_bound(L); // Corrected code: Use lower_bound with query range
        auto X_r = x_to_ptr.upper_bound(R); // Corrected code: Use upper_bound with query range
        // Calculate the answer for the current query
        int ans = P[R] - P[L]; // Corrected code: Use the actual value of P[R] - P[L] instead of hardcoded value 0
        cout << ans << endl; // Output the answer for the query
    }

    return 0; // Return 0 to indicate successful completion of the program
}