#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0);
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    // Sort X and create an index array for binary search
    vector<int> sorted_X = X;
    sort(sorted_X.begin(), sorted_X.end());
    vector<int> original_indices(N);
    rep(i, N) original_indices[i] = i;

    // Function to perform binary search and return the original index
    auto find_index = [&](int val) -> int {
        auto it = lower_bound(sorted_X.begin(), sorted_X.end(), val);
        if (it == sorted_X.end()) return N; // If val is greater than all elements
        // Find the original index of the found element
        int idx = distance(sorted_X.begin(), it);
        return original_indices[idx];
    };

    int Q;
    cin >> Q;
    rep(q, Q) {
        int L, R;
        cin >> L >> R;
        int l = find_index(L);
        int r = find_index(R + 1); // Use R + 1 to find the first element greater than R
        if (r > l) {
            r--; // Adjust r to the last valid index within the range
        }
        ll ans = P[r + 1] - P[l];
        cout << ans << endl;
    }

    return 0;
}