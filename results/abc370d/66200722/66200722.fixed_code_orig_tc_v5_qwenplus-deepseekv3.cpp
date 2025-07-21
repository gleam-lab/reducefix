#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h + 1), col_walls(w + 1);
    for (int i = 1; i <= h; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(h + 1);
    }
    
    long long remaining = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (!row_walls[r].count(c)) {
            // Wall exists, destroy it
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining--;
        } else {
            // No wall, destroy the first walls in four directions
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            it_left--;
            int left = *it_left;
            if (left >= 1 && !row_walls[r].count(left)) {
                row_walls[r].insert(left);
                col_walls[left].insert(r);
                remaining--;
            }
            
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            int right = *it_right;
            if (right <= w && !row_walls[r].count(right)) {
                row_walls[r].insert(right);
                col_walls[right].insert(r);
                remaining--;
            }
            
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            it_up--;
            int up = *it_up;
            if (up >= 1 && !col_walls[c].count(up)) {
                col_walls[c].insert(up);
                row_walls[up].insert(c);
                remaining--;
            }
            
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            int down = *it_down;
            if (down <= h && !col_walls[c].count(down)) {
                col_walls[c].insert(down);
                row_walls[down].insert(c);
                remaining--;
            }
        }
    }
    
    cout << remaining << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}