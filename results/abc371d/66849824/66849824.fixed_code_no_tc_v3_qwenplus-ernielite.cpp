#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// Removed the reps macro as it's not a standard C++ loop structure. Use regular for loops.
// The rep macro is already defined as a for loop with proper bounds.

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N; // Read the number of elements in the array X and P
    vector<ll> P(N + 1); // Create a vector P to store the prefix sums
    P[0] = 0; // Initialize the first element of P as 0

    // Read the array X and calculate the prefix sums in P
    for (int i = 1; i <= N; ++i) {
        cin >> P[i]; // Read the value of P[i]
        P[i] += P[i - 1]; // Calculate the prefix sum
    }

    map<int, int> x_to_ptr; // Create a map to store the indices of X in sorted order based on their values
    for (int i = 0; i < N; ++i) {
        int x_val;
        cin >> x_val; // Read the value of X[i]
        x_to_ptr[x_val] = i; // Store the index i in the map with key x_val
    }

    // Query processing logic starts here
    int Q;
    cin >> Q; // Read the number of queries
    while (Q--) { // Process each query
        int L, R; // Query limits L and R
        cin >> L >> R; // Read the query limits
        
        // Use lower_bound and upper_bound to find indices l and r in x_to_ptr map for L and R respectively
        auto X_l_it = x_to_ptr.lower_bound(L); // Find the first element >= L in x_to_ptr
        auto X_r_it = x_to_ptr.upper_bound(R); // Find the first element > R in x_to_ptr (exclusive)
        // Note: If L is not found in x_to_ptr, X_l_it will be equal to x_to_ptr.end() and l will be set to N below.
        // If R is found, we need to decrement R's index by 1 since we are using an exclusive bound.
        int l = (X_l_it == x_to_ptr.end()) ? N : X_l_it->second; // If L not found, set l to N. Otherwise get the index from X_l_it.
        int r = (X_r_it != x_to_ptr.begin()) ? (X_r_it - 1)->second : N; // If R is found, get the previous element's index from X_r_it. Otherwise set r to N.
        // Adjusting r for upper bound exclusive nature.
        // Note: In this case, we assume that if R is not found, we still want to return the last element's value from P, so we set r to N as well. This might depend on the actual problem requirements.
        // If you want to handle R not found differently, you would need to adjust this logic accordingly.
        
        // Now we can calculate the answer by subtracting the prefix sum at l from the prefix sum at r (inclusive)
        ll ans = (r > 0) ? P[r] - P[l] : 0; // Check if l and r are valid indices before calculating the difference in prefix sums.
        cout << ans << endl; // Output the answer for this query
    }
}