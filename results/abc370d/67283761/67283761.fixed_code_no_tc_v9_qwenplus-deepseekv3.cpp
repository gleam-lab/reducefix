#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H + 2), col_walls(W + 2);
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }
    
    int broken = 0;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            broken++;
        } else {
            // Up
            auto it = col_walls[c].lower_bound(r);
            --it;
            int up = *it;
            if (up > 0 && row_walls[up].count(c)) {
                row_walls[up].erase(c);
                col_walls[c].erase(up);
                broken++;
            }
            
            // Down
            it = col_walls[c].upper_bound(r);
            int down = *it;
            if (down <= H && row_walls[down].count(c)) {
                row_walls[down].erase(c);
                col_walls[c].erase(down);
                broken++;
            }
            
            // Left
            it = row_walls[r].lower_bound(c);
            --it;
            int left = *it;
            if (left > 0 && col_walls[left].count(r)) {
                col_walls[left].erase(r);
                row_walls[r].erase(left);
                broken++;
            }
            
            // Right
            it = row_walls[r].upper_bound(c);
            int right = *it;
            if (right <= W && col_walls[right].count(r)) {
                col_walls[right].erase(r);
                row_walls[r].erase(right);
                broken++;
            }
        }
    }
    
    cout << H * W - broken << '\n';
    
    return 0;
}