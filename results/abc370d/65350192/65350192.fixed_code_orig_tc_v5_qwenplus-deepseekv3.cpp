#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    int walls_remaining = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Wall exists at (r,c) - destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            walls_remaining--;
        } else {
            // Destroy first walls in each direction
            // Up
            auto up_it = col_walls[c].lower_bound(r);
            if (up_it != col_walls[c].begin()) {
                up_it--;
                int i = *up_it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                walls_remaining--;
            }
            
            // Down
            auto down_it = col_walls[c].lower_bound(r);
            if (down_it != col_walls[c].end()) {
                int i = *down_it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                walls_remaining--;
            }
            
            // Left
            auto left_it = row_walls[r].lower_bound(c);
            if (left_it != row_walls[r].begin()) {
                left_it--;
                int j = *left_it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                walls_remaining--;
            }
            
            // Right
            auto right_it = row_walls[r].lower_bound(c);
            if (right_it != row_walls[r].end()) {
                int j = *right_it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                walls_remaining--;
            }
        }
    }
    
    cout << walls_remaining << "\n";
    return 0;
}