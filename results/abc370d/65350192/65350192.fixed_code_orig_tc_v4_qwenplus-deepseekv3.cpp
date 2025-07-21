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

    int ans = h * w;
    
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // Find first wall in each direction
            // Right
            auto it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                ans--;
            }
            
            // Left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                it--;
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                ans--;
            }
            
            // Down
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                ans--;
            }
            
            // Up
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                it--;
                int i = *it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                ans--;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}