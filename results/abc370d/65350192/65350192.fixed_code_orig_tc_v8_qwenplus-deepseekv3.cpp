#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h+1), col_walls(w+1);
    vector<vector<bool>> wall_exists(h+1, vector<bool>(w+1, true));
    
    // Initialize sets with all walls
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (wall_exists[r][c]) {
            // Destroy this wall
            wall_exists[r][c] = false;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Destroy nearest walls in four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int target_r = *it_up;
                wall_exists[target_r][c] = false;
                row_walls[target_r].erase(c);
                col_walls[c].erase(target_r);
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int target_r = *it_down;
                wall_exists[target_r][c] = false;
                row_walls[target_r].erase(c);
                col_walls[c].erase(target_r);
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int target_c = *it_left;
                wall_exists[r][target_c] = false;
                row_walls[r].erase(target_c);
                col_walls[target_c].erase(r);
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int target_c = *it_right;
                wall_exists[r][target_c] = false;
                row_walls[r].erase(target_c);
                col_walls[target_c].erase(r);
            }
        }
    }
    
    // Count remaining walls
    int remaining = 0;
    for (int i = 1; i <= h; i++) {
        remaining += row_walls[i].size();
    }
    
    cout << remaining << "\n";
    return 0;
}