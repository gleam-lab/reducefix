#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H+2);  // for each row, columns with walls
    vector<set<int>> col_walls(W+2);  // for each column, rows with walls
    
    // Initialize with all walls present
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int remaining = H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            // Wall exists at (r,c) - remove it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // No wall at (r,c) - remove first walls in each direction
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int col = *it_left;
                row_walls[r].erase(it_left);
                col_walls[col].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int col = *it_right;
                row_walls[r].erase(it_right);
                col_walls[col].erase(r);
                remaining--;
            }
            
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int row = *it_up;
                col_walls[c].erase(it_up);
                row_walls[row].erase(c);
                remaining--;
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int row = *it_down;
                col_walls[c].erase(it_down);
                row_walls[row].erase(c);
                remaining--;
            }
        }
    }

    cout << remaining << '\n';
    return 0;
}