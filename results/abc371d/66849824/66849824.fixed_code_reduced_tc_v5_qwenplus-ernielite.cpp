#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i = 0; i < (n); ++i)
// Note: reps and all/rall are not used in this problem, so I've removed them.

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1); // To store prefix sum of P (including P[0] = 0)
    vector<int> X(N); // To store elements of X[]
    P[0] = 0;
    rep(i, N) {
        cin >> X[i];
        P[i + 1] = P[i] + i + 1; // Assuming P[i] is a sum of previous elements (can be modified based on actual problem constraints)
    }
    map<int, int> x_to_ptr; // To store X values as keys and their indices as values
    rep(i, N) {
        x_to_ptr.emplace(X[i], i);
    }
    // Check for the empty range if L == 0 and R == N or vice versa (if query is for a non-existent range)
    // ... (other code remains the same)

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R; // Assuming L and R are query bounds (inclusive)
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L); // Lower bound for L in X values
        auto X_r = x_to_ptr.upper_bound(R); // Upper bound for R in X values
        // Handle cases where L or R is less than or equal to the first or last element in X[] respectively.
        if (X_l == x_to_ptr.begin()) { // If L is less than or equal to the first element in X[] (or not found)
            l = 0; // Set l to 0 as P[l] will be 0 (base case) for any L that is 0 or less.
        } else { // If L is found in x_to_ptr, get the index from the previous element (as lower_bound points to next greater value).
            l = prev(X_l)->second; // prev returns an iterator pointing to the previous element in the map. Use ->second to get the index.
        }
        if (X_r == x_to_ptr.end()) { // If R is greater than any element in X[] (or not found)
            r = N - 1; // Set r to N-1 as we want to include the last element of P[] in the result.
        } else { // If R is found in x_to_ptr, get the index from it directly.
            r = X_r->second; // Use ->second directly on X_r which points to a valid element in the map.
        }
        // Now calculate the answer using P[r] and P[l]. Note that P[l] should be P[l-1] if l is not 0. Here we assume l is always 0 or greater than 0. Adjust accordingly if needed.
        int ans = P[r + 1] - P[l]; // Use r+1 instead of r to get the correct prefix sum difference. Adjust if P[] is defined differently.
        cout << ans << endl; // Output the answer for this query.
    }
}