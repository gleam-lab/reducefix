#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }

    long long remaining = (long long)H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row_walls[R].count(C)) {
            // Already destroyed, do nothing
            continue;
        }

        // Check if current cell has a wall
        if (row_walls[R].insert(C).second && col_walls[C].insert(R).second) {
            remaining--;
        } else {
            // No wall here, destroy adjacent walls
            // Left
            auto it_left = row_walls[R].lower_bound(C);
            --it_left;
            if (*it_left > 0) {
                int left_col = *it_left;
                if (row_walls[R].erase(left_col) && col_walls[left_col].erase(R)) {
                    remaining--;
                }
            }
            // Right
            auto it_right = row_walls[R].upper_bound(C);
            if (*it_right <= W) {
                int right_col = *it_right;
                if (row_walls[R].erase(right_col) && col_walls[right_col].erase(R)) {
                    remaining--;
                }
            }
            // Up
            auto it_up = col_walls[C].lower_bound(R);
            --it_up;
            if (*it_up > 0) {
                int up_row = *it_up;
                if (col_walls[C].erase(up_row) && row_walls[up_row].erase(C)) {
                    remaining--;
                }
            }
            // Down
            auto it_down = col_walls[C].upper_bound(R);
            if (*it_down <= H) {
                int down_row = *it_down;
                if (col_walls[C].erase(down_row) && row_walls[down_row].erase(C)) {
                    remaining--;
                }
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}