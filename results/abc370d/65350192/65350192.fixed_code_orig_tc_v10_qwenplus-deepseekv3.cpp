#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    
    // Initialize all walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Direct hit - destroy this wall
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Find first walls in four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int up_row = *it_up;
                row_walls[up_row].erase(c);
                col_walls[c].erase(up_row);
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int down_row = *it_down;
                row_walls[down_row].erase(c);
                col_walls[c].erase(down_row);
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int left_col = *it_left;
                row_walls[r].erase(left_col);
                col_walls[left_col].erase(r);
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int right_col = *it_right;
                row_walls[r].erase(right_col);
                col_walls[right_col].erase(r);
            }
        }
    }
    
    // Count remaining walls
    int remaining = 0;
    for (int i = 0; i < h; ++i) {
        remaining += row_walls[i].size();
    }
    
    cout << remaining << '\n';
    return 0;
}