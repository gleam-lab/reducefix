#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);
    
    // Initialize all walls
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Direct hit - remove this wall
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Find first walls in all four directions
            
            // Up (column)
            auto col_it = col_walls[c].lower_bound(r);
            if (col_it != col_walls[c].begin()) {
                col_it--;
                int wall_row = *col_it;
                row_walls[wall_row].erase(c);
                col_walls[c].erase(wall_row);
            }
            
            // Down (column)
            col_it = col_walls[c].lower_bound(r);
            if (col_it != col_walls[c].end()) {
                int wall_row = *col_it;
                row_walls[wall_row].erase(c);
                col_walls[c].erase(wall_row);
            }
            
            // Left (row)
            auto row_it = row_walls[r].lower_bound(c);
            if (row_it != row_walls[r].begin()) {
                row_it--;
                int wall_col = *row_it;
                row_walls[r].erase(wall_col);
                col_walls[wall_col].erase(r);
            }
            
            // Right (row)
            row_it = row_walls[r].lower_bound(c);
            if (row_it != row_walls[r].end()) {
                int wall_col = *row_it;
                row_walls[r].erase(wall_col);
                col_walls[wall_col].erase(r);
            }
        }
    }
    
    // Count remaining walls
    ll ans = 0;
    for (const auto& row : row_walls) {
        ans += row.size();
    }
    cout << ans << "\n";
    return 0;
}