#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2); // 1-based indexing
    vector<set<int>> col_walls(W + 2); // 1-based indexing
    
    // Initialize walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    long long remaining_walls = (long long)H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        
        if (row_walls[R].count(C)) {
            // There is a wall at (R, C)
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining_walls--;
        } else {
            // No wall at (R, C), find the first walls in four directions
            // Up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int up_row = *it_up;
                if (row_walls[up_row].count(C)) {
                    row_walls[up_row].erase(C);
                    col_walls[C].erase(up_row);
                    remaining_walls--;
                }
            }
            // Down
            auto it_down = col_walls[C].upper_bound(R);
            if (it_down != col_walls[C].end()) {
                int down_row = *it_down;
                if (row_walls[down_row].count(C)) {
                    row_walls[down_row].erase(C);
                    col_walls[C].erase(down_row);
                    remaining_walls--;
                }
            }
            // Left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int left_col = *it_left;
                if (col_walls[left_col].count(R)) {
                    col_walls[left_col].erase(R);
                    row_walls[R].erase(left_col);
                    remaining_walls--;
                }
            }
            // Right
            auto it_right = row_walls[R].upper_bound(C);
            if (it_right != row_walls[R].end()) {
                int right_col = *it_right;
                if (col_walls[right_col].count(R)) {
                    col_walls[right_col].erase(R);
                    row_walls[R].erase(right_col);
                    remaining_walls--;
                }
            }
        }
    }
    
    cout << remaining_walls << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}