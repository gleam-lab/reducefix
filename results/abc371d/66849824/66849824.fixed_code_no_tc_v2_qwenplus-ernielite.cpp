#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> prefixSum(N + 1, 0); // Use prefixSum instead of P to make it more descriptive
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        prefixSum[i + 1] = prefixSum[i] + 1; // Assuming increments of 1 for simplicity, adjust if needed
    }
    map<int, int> X_to_index; // Use X_to_index instead of x_to_ptr for clarity
    for (int i = 0; i < N; ++i) {
        X_to_index[X[i]] = i; // Build the map from X values to their indices
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R; // Read the query range [L, R]
        auto X_it_l = X_to_index.lower_bound(L); // Find the index for the lower bound of L in X_to_index
        auto X_it_r = prev(X_to_index.upper_bound(R)); // Find the index for the previous to upper bound of R in X_to_index (to handle R itself)
        if (X_it_l == X_to_index.end()) {
            // If L is greater than any value in X, consider the answer as 0 or appropriate value based on the problem context
            cout << "0" << endl; // Adjust based on problem's context for when L is out of range
        } else if (X_it_r == X_to_index.begin()) {
            // If R is less than any value in X, consider the answer as the difference between prefix sums at 0 and the index of R (or appropriate value)
            cout << prefixSum[X_it_l->second] << endl; // Adjust based on problem's context for when R is out of range
        } else {
            // Calculate the difference between prefix sums at indices for L and R ranges
            ll ans = prefixSum[X_it_r->second + 1] - prefixSum[X_it_l->second]; // Adjust indices based on problem's context for prefixSum array indexing
            cout << ans << endl;
        }
    }
    return 0;
}