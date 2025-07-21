#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each column, keep track of remaining walls in that column (row indices)
    vector<set<int>> col_walls(W);
    // For each row, keep track of remaining walls in that row (column indices)
    vector<set<int>> row_walls(H);

    // Initialize all walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            col_walls[j].insert(i);
            row_walls[i].insert(j);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Check if there's a wall at the bomb position
        auto it = row_walls[R].find(C);
        if (it != row_walls[R].end()) {
            // Wall exists, destroy it
            row_walls[R].erase(C);
            col_walls[C].erase(R);
        } else {
            // No wall at position, destroy first walls in each direction

            // Up (in the same column, look for largest row < R)
            {
                auto it = col_walls[C].lower_bound(R);
                if (it != col_walls[C].begin()) {
                    --it;
                    int r = *it;
                    row_walls[r].erase(C);
                    col_walls[C].erase(it);
                }
            }

            // Down (in the same column, look for smallest row > R)
            {
                auto it = col_walls[C].lower_bound(R);
                if (it != col_walls[C].end()) {
                    int r = *it;
                    row_walls[r].erase(C);
                    col_walls[C].erase(it);
                }
            }

            // Left (in the same row, look for largest column < C)
            {
                auto it = row_walls[R].lower_bound(C);
                if (it != row_walls[R].begin()) {
                    --it;
                    int c = *it;
                    col_walls[c].erase(R);
                    row_walls[R].erase(it);
                }
            }

            // Right (in the same row, look for smallest column > C)
            {
                auto it = row_walls[R].lower_bound(C);
                if (it != row_walls[R].end()) {
                    int c = *it;
                    col_walls[c].erase(R);
                    row_walls[R].erase(it);
                }
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < W; ++i) {
        ans += col_walls[i].size();
    }
    cout << ans << endl;

    return 0;
}