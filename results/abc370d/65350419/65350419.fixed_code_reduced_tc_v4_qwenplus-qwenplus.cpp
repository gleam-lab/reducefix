#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, maintain the set of remaining wall positions
    vector<set<int>> rows(H), cols(W);

    // Initialize all walls present
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C;

        // Check if there's a wall at (R, C)
        if (rows[R].count(C)) {
            // Wall exists - just destroy it
            rows[R].erase(C);
            cols[C].erase(R);
        } else {
            // No wall here - destroy first walls in four directions

            // Up
            auto uIt = cols[C].lower_bound(R);
            if (uIt != cols[C].begin()) {
                --uIt;
                int ur = *uIt;
                rows[ur].erase(C);
                cols[C].erase(ur);
            }

            // Down
            auto dIt = cols[C].upper_bound(R);
            if (dIt != cols[C].end()) {
                int dr = *dIt;
                rows[dr].erase(C);
                cols[C].erase(dr);
            }

            // Left
            auto lIt = rows[R].lower_bound(C);
            if (lIt != rows[R].begin()) {
                --lIt;
                int lc = *lIt;
                cols[lc].erase(R);
                rows[R].erase(lIt);
            }

            // Right
            auto rIt = rows[R].upper_bound(C);
            if (rIt != rows[R].end()) {
                int rc = *rIt;
                cols[rc].erase(R);
                rows[R].erase(rIt);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += rows[i].size();
    }

    cout << ans << "\n";
    return 0;
}