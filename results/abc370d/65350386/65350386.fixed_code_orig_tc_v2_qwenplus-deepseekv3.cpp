#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    rep(i,h) rep(j,w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    int remaining = h * w;
    
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Wall exists at this location - destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // No wall - destroy first walls in each direction
            // Up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                it--;
                int y = *it;
                row_walls[y].erase(c);
                col_walls[c].erase(y);
                remaining--;
            }
            
            // Down
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].end()) {
                int y = *it;
                row_walls[y].erase(c);
                col_walls[c].erase(y);
                remaining--;
            }
            
            // Left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                it--;
                int x = *it;
                row_walls[r].erase(x);
                col_walls[x].erase(r);
                remaining--;
            }
            
            // Right
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].end()) {
                int x = *it;
                row_walls[r].erase(x);
                col_walls[x].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}