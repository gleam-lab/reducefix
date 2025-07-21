#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h + 1);
    vector<set<int>> col_walls(w + 1);
    
    for (int i = 1; i <= h; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(h + 1);
    }
    
    long long remaining_walls = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c) == 0) {
            // Wall exists at (r, c), destroy it
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining_walls--;
        } else {
            // No wall at (r, c), destroy first walls in four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            it_up--;
            int up = *it_up;
            if (up >= 1 && row_walls[up].count(c) == 0) {
                row_walls[up].insert(c);
                col_walls[c].insert(up);
                remaining_walls--;
            }
            
            // Down
            auto it_down = col_walls[c].upper_bound(r);
            int down = *it_down;
            if (down <= h && row_walls[down].count(c) == 0) {
                row_walls[down].insert(c);
                col_walls[c].insert(down);
                remaining_walls--;
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            it_left--;
            int left = *it_left;
            if (left >= 1 && col_walls[left].count(r) == 0) {
                col_walls[left].insert(r);
                row_walls[r].insert(left);
                remaining_walls--;
            }
            
            // Right
            auto it_right = row_walls[r].upper_bound(c);
            int right = *it_right;
            if (right <= w && col_walls[right].count(r) == 0) {
                col_walls[right].insert(r);
                row_walls[r].insert(right);
                remaining_walls--;
            }
        }
    }
    
    cout << remaining_walls << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}