#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);
    
    // Initialize all walls as present
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }

    int remaining_walls = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Wall exists at (r,c) - destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining_walls--;
        } else {
            // No wall at (r,c) - destroy first walls in each direction
            
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                it_up--;
                int destroyed_row = *it_up;
                row_walls[destroyed_row].erase(c);
                col_walls[c].erase(destroyed_row);
                remaining_walls--;
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int destroyed_row = *it_down;
                row_walls[destroyed_row].erase(c);
                col_walls[c].erase(destroyed_row);
                remaining_walls--;
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                it_left--;
                int destroyed_col = *it_left;
                row_walls[r].erase(destroyed_col);
                col_walls[destroyed_col].erase(r);
                remaining_walls--;
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int destroyed_col = *it_right;
                row_walls[r].erase(destroyed_col);
                col_walls[destroyed_col].erase(r);
                remaining_walls--;
            }
        }
    }
    
    cout << remaining_walls << "\n";
    return 0;
}