#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // We'll use two separate sets for each row and column
    vector<set<int>> row_walls(h), col_walls(w);
    
    // Initialize all walls
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    
    int ans = h * w;
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Wall exists here - destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // No wall here - destroy first walls in four directions
            // Up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int i = *it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                ans--;
            }
            
            // Down
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                ans--;
            }
            
            // Left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                ans--;
            }
            
            // Right
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                ans--;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}