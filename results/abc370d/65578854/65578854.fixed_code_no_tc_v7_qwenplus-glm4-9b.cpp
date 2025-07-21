#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> X(H), Y(W);

    // Initialize the sets with all walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            X[i].insert(j);
            Y[j].insert(i);
        }
    }

    ll ans = H * W; // Total number of walls initially

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to zero-based index

        // Attempt to destroy the wall at (r, c)
        if (X[r].erase(c) || Y[c].erase(r)) {
            // Wall was destroyed
        } else {
            // No wall at (r, c), so we need to remove the first wall in each direction
            // Check above
            auto it = upper_bound(Y[c].begin(), Y[c].end(), r);
            if (it != Y[c].begin()) {
                it--;
                X[*it].erase(c);
                ans--;
            }
            // Check below
            it = lower_bound(Y[c].begin(), Y[c].end(), r);
            if (it != Y[c].end()) {
                X[*it].erase(c);
                ans--;
            }
            // Check left
            it = upper_bound(X[r].begin(), X[r].end(), c);
            if (it != X[r].begin()) {
                it--;
                Y[*it].erase(r);
                ans--;
            }
            // Check right
            it = lower_bound(X[r].begin(), X[r].end(), c);
            if (it != X[r].end()) {
                Y[*it].erase(r);
                ans--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}