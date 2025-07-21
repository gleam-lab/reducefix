#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
// Note: reps and all/rall macros are not used in this solution
// We also don't need Yes/YES macros as they are not used in the solution

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) {
        cin >> X[i];
        P[i + 1] = P[i] + X[i]; // Calculate prefix sum here instead of after reading all p values
    }
    map<int, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr.emplace(X[i], i); // Store indices in the map for quick access later
    }

    int Q;
    cin >> Q;
    while (Q--) { // Use a while loop to process multiple queries if needed (not shown in failing case)
        ll L, R; // Use ll to handle large numbers for prefix sum calculations
        cin >> L >> R;
        if (L > R) continue; // Skip queries where L >= R (empty or invalid range)
        auto X_l = x_to_ptr.lower_bound(L); // Search for lower bound of L (could be equal or greater)
        if (X_l != x_to_ptr.begin()) --X_l; // Decrement to get correct index for lower bound (if not equal to L)
        auto X_r = x_to_ptr.upper_bound(R); // Search for upper bound of R (strictly greater)
        if (X_r != x_to_ptr.end()) --X_r; // Decrement to get correct index for upper bound (if not at end)
        int l = X_l->second; // Get left index for L value in X[]
        int r = (X_r != x_to_ptr.end()) ? X_r->second : N; // Get right index or N if not found in X[] due to upper bound (i.e., last index)
        ll ans = P[r] - P[l]; // Calculate prefix sum difference as required by the problem description
        cout << ans << '\n'; // Output the result of the query prefix sum calculation
    }
}