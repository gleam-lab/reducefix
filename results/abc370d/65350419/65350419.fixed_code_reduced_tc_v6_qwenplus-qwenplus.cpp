#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_sets(H), col_sets(W);
    
    // Initialize sets with all column indices for each row and all row indices for each column
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row_sets[r].insert(c);
            col_sets[c].insert(r);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (row_sets[R].count(C)) {
            // If there's a wall at (R,C), remove it
            row_sets[R].erase(C);
            col_sets[C].erase(R);
        } else {
            // Remove the first wall above
            auto it = col_sets[C].lower_bound(R);
            if (it != col_sets[C].begin()) {
                it--;
                int r = *it;
                row_sets[r].erase(C);
                col_sets[C].erase(r);
            }

            // Remove the first wall below
            it = col_sets[C].lower_bound(R);
            if (it != col_sets[C].end()) {
                int r = *it;
                row_sets[r].erase(C);
                col_sets[C].erase(r);
            }

            // Remove the first wall to the left
            auto jt = row_sets[R].lower_bound(C);
            if (jt != row_sets[R].begin()) {
                jt--;
                int c = *jt;
                col_sets[c].erase(R);
                row_sets[R].erase(c);
            }

            // Remove the first wall to the right
            jt = row_sets[R].lower_bound(C);
            if (jt != row_sets[R].end()) {
                int c = *jt;
                col_sets[c].erase(R);
                row_sets[R].erase(c);
            }
        }
    }

    int ans = 0;
    for (int r = 0; r < H; ++r) {
        ans += row_sets[r].size();
    }

    cout << ans << "\n";
    return 0;
}