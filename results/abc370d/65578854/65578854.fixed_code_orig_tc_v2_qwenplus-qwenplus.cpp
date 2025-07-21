#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Each row has a set of active columns (walls)
    vector<set<int>> row(W);
    // Each column has a set of active rows (walls)
    vector<set<int>> col(H);

    // Initialize all walls
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row[r].insert(c);
            col[c].insert(r);
        }
    }

    long long total_walls = 1LL * H * W;

    auto destroy_wall = [&](int r, int c) {
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            total_walls--;
        }
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (!row[R].count(C)) {
            // Wall already destroyed, now look in 4 directions

            // Up (r < R)
            auto it = col[C].lower_bound(R);
            if (it != col[C].begin()) {
                --it;
                destroy_wall(*it, C);
            }

            // Down (r > R)
            it = col[C].lower_bound(R);
            if (it != col[C].end() && *it != *col[C].lower_bound(R)) {
                destroy_wall(*it, C);
            } else if (it != col[C].end()) {
                ++it;
                if (it != col[C].end()) {
                    destroy_wall(*it, C);
                }
            }

            // Left (c < C)
            it = row[R].lower_bound(C);
            if (it != row[R].begin()) {
                --it;
                destroy_wall(R, *it);
            }

            // Right (c > C)
            it = row[R].lower_bound(C);
            if (it != row[R].end() && *it != *row[R].lower_bound(C)) {
                destroy_wall(R, *it);
            } else if (it != row[R].end()) {
                ++it;
                if (it != row[R].end()) {
                    destroy_wall(R, *it);
                }
            }
        } else {
            // There is a wall here, destroy it directly
            destroy_wall(R, C);
        }
    }

    cout << total_walls << '\n';
}