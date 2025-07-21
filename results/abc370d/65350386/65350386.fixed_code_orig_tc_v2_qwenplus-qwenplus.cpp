#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

// Data structures to represent rows and columns as sets of remaining wall positions
vector<set<int>> row_walls, col_walls;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize walls in each row and column
    row_walls.resize(H);
    col_walls.resize(W);
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row_walls[r].insert(c);
            col_walls[c].insert(r);
        }
    }

    rep(_, Q) {
        int R, C;
        cin >> R >> C;
        R--;  // convert to 0-based index
        C--;

        // Check if there's a wall at (R, C)
        auto row_it = row_walls[R].find(C);
        if (row_it != row_walls[R].end()) {
            // Direct bomb: destroy wall at (R, C)
            row_walls[R].erase(row_it);
            col_walls[C].erase(col_walls[C].find(R));
        } else {
            // Indirect bomb: destroy first walls in four directions

            // Up
            auto col_it_up = col_walls[C].lower_bound(R);
            if (col_it_up != col_walls[C].begin()) {
                int r = *prev(col_it_up);
                row_walls[r].erase(C);
                col_walls[C].erase(r);
            }

            // Down
            auto col_it_down = col_walls[C].lower_bound(R);
            if (col_it_down != col_walls[C].end()) {
                int r = *col_it_down;
                row_walls[r].erase(C);
                col_walls[C].erase(r);
            }

            // Left
            auto row_it_left = row_walls[R].lower_bound(C);
            if (row_it_left != row_walls[R].begin()) {
                int c = *prev(row_it_left);
                col_walls[c].erase(R);
                row_walls[R].erase(c);
            }

            // Right
            auto row_it_right = row_walls[R].lower_bound(C);
            if (row_it_right != row_walls[R].end()) {
                int c = *row_it_right;
                col_walls[c].erase(R);
                row_walls[R].erase(c);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (const auto& s : row_walls) {
        ans += s.size();
    }

    cout << ans << endl;

    return 0;
}