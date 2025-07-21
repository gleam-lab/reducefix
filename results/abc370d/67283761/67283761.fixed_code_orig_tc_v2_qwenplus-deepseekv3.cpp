#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H+2);
    vector<set<int>> col_walls(W+2);
    
    // Initialize with sentinel values and actual walls
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W+1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H+1);
    }
    
    int remaining = H * W;
    
    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            // Wall exists - destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Find nearest walls in four directions
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            it_left--;
            int left = *it_left;
            if (left > 0 && row_walls[r].count(left)) {
                row_walls[r].erase(left);
                col_walls[left].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            int right = *it_right;
            if (right <= W && row_walls[r].count(right)) {
                row_walls[r].erase(right);
                col_walls[right].erase(r);
                remaining--;
            }
            
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            it_up--;
            int up = *it_up;
            if (up > 0 && col_walls[c].count(up)) {
                col_walls[c].erase(up);
                row_walls[up].erase(c);
                remaining--;
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            int down = *it_down;
            if (down <= H && col_walls[c].count(down)) {
                col_walls[c].erase(down);
                row_walls[down].erase(c);
                remaining--;
            }
        }
    }
    
    cout << remaining << endl;
    return 0;
}