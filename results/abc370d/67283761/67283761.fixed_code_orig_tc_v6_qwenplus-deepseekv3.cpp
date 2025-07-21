#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H+1);  // 1-based
    vector<set<int>> col_walls(W+1);  // 1-based
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    int total_walls = H * W;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            // Direct hit - destroy this wall
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            total_walls--;
        } else {
            // Search in four directions
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int col = *it_left;
                row_walls[r].erase(col);
                col_walls[col].erase(r);
                total_walls--;
            }
            
            // Right
            auto it_right = row_walls[r].upper_bound(c);
            if (it_right != row_walls[r].end()) {
                int col = *it_right;
                row_walls[r].erase(col);
                col_walls[col].erase(r);
                total_walls--;
            }
            
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int row = *it_up;
                col_walls[c].erase(row);
                row_walls[row].erase(c);
                total_walls--;
            }
            
            // Down
            auto it_down = col_walls[c].upper_bound(r);
            if (it_down != col_walls[c].end()) {
                int row = *it_down;
                col_walls[c].erase(row);
                row_walls[row].erase(c);
                total_walls--;
            }
        }
    }
    
    cout << total_walls << endl;
    
    return 0;
}