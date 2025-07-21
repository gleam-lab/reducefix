#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    int remaining = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Direct hit - destroy this wall
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Find nearest walls in all four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                int pos = *prev(it_up);
                row_walls[pos].erase(c);
                col_walls[c].erase(pos);
                remaining--;
            }
            
            // Down
            auto it_down = col_walls[c].upper_bound(r);
            if (it_down != col_walls[c].end()) {
                int pos = *it_down;
                row_walls[pos].erase(c);
                col_walls[c].erase(pos);
                remaining--;
            }
            
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                int pos = *prev(it_left);
                row_walls[r].erase(pos);
                col_walls[pos].erase(r);
                remaining--;
            }
            
            // Right
            auto it_right = row_walls[r].upper_bound(c);
            if (it_right != row_walls[r].end()) {
                int pos = *it_right;
                row_walls[r].erase(pos);
                col_walls[pos].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}