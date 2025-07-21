#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
    int N, Q;
    cin >> N; // Read the size of array P and X
    vector<ll> P(N + 1), X(N);
    map<int, int> x_to_ptr; // Use a map to store X values as keys and their indices as values
    P[0] = 0; // Initialize P[0] to 0 as per the problem's requirement
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read X values
        x_to_ptr[X[i]] = i; // Store X values and their indices in the map
        cin >> P[i + 1]; // Read P values (starting from index 1)
    }
    // Process queries
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R; // Read L and R for each query
        auto X_l_it = x_to_ptr.lower_bound(L); // Find the iterator for the lower bound of L in X values
        auto X_r_it = x_to_ptr.upper_bound(R); // Find the iterator for the upper bound of R in X values
        // Determine the indices for l and r based on the map iterators
        int l = (X_l_it != x_to_ptr.begin()) ? (X_l_it - 1)->second : N; // If L is less than the first X value, set l as N (index of last element)
        int r = X_r_it != x_to_ptr.end() ? X_r_it->second : N; // If R is greater than any X value, set r as N (index of last element)
        // Calculate and print the answer for each query (difference between P[r] and P[l])
        ll ans = P[r] - P[l]; // Use ll to ensure correct arithmetic operations for large numbers
        cout << ans << endl; // Print the answer for each query
    }
    return 0; // Return 0 to indicate successful execution (not strictly necessary in main() but good practice)
}