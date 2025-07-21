#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // For each row and column, keep track of which columns/rows have bombs
    vector<set<int>> row_bombs(h), col_bombs(w);
    
    // Initialize all cells as having walls (total walls = h * w)
    long long remaining_walls = 1LL * h * w;
    
    // For counting walls destroyed in each cell (to avoid double-counting)
    vector<vector<bool>> wall_destroyed(h, vector<bool>(w, false));
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (!wall_destroyed[r][c]) {
            // Case 1: Bomb placed on a wall - destroy it
            wall_destroyed[r][c] = true;
            remaining_walls--;
            
            // Add bomb position to tracking sets
            row_bombs[r].insert(c);
            col_bombs[c].insert(r);
        } else {
            // Case 2: Bomb placed on an empty cell - look in 4 directions
            
            // Up
            auto it = col_bombs[c].lower_bound(r);
            if (it != col_bombs[c].begin()) {
                it--;
                int target_r = *it;
                if (!wall_destroyed[target_r][c]) {
                    wall_destroyed[target_r][c] = true;
                    remaining_walls--;
                }
            }
            
            // Down
            it = col_bombs[c].upper_bound(r);
            if (it != col_bombs[c].end()) {
                int target_r = *it;
                if (!wall_destroyed[target_r][c]) {
                    wall_destroyed[target_r][c] = true;
                    remaining_walls--;
                }
            }
            
            // Left
            auto sit = row_bombs[r].lower_bound(c);
            if (sit != row_bombs[r].begin()) {
                sit--;
                int target_c = *sit;
                if (!wall_destroyed[r][target_c]) {
                    wall_destroyed[r][target_c] = true;
                    remaining_walls--;
                }
            }
            
            // Right
            sit = row_bombs[r].upper_bound(c);
            if (sit != row_bombs[r].end()) {
                int target_c = *sit;
                if (!wall_destroyed[r][target_c]) {
                    wall_destroyed[r][target_c] = true;
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
}