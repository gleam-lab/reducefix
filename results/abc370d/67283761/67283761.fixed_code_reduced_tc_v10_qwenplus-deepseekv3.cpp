#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);
    
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }
    
    int walls_remaining = H * W;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            walls_remaining--;
        } else {
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            --it_left;
            int left = *it_left;
            if (left >= 1 && left <= W) {
                if (row_walls[r].count(left)) {
                    row_walls[r].erase(left);
                    col_walls[left].erase(r);
                    walls_remaining--;
                }
            }
            
            // Right
            auto it_right = row_walls[r].upper_bound(c);
            int right = *it_right;
            if (right >= 1 && right <= W) {
                if (row_walls[r].count(right)) {
                    row_walls[r].erase(right);
                    col_walls[right].erase(r);
                    walls_remaining--;
                }
            }
            
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            --it_up;
            int up = *it_up;
            if (up >= 1 && up <= H) {
                if (col_walls[c].count(up)) {
                    col_walls[c].erase(up);
                    row_walls[up].erase(c);
                    walls_remaining--;
                }
            }
            
            // Down
            auto it_down = col_walls[c].upper_bound(r);
            int down = *it_down;
            if (down >= 1 && down <= H) {
                if (col_walls[c].count(down)) {
                    col_walls[c].erase(down);
                    row_walls[down].erase(c);
                    walls_remaining--;
                }
            }
        }
    }
    
    cout << walls_remaining << '\n';
    
    return 0;
}