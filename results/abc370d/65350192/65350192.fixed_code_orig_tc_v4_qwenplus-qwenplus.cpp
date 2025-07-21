#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    // Represent grid with sets that track wall positions
    vector<set<int>> row_walls(h), col_walls(w);
    
    // Initialize walls in each row and column
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    for (int _ = 0; _ < q; ++_) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        // Check if there's a wall at the bomb position
        if (row_walls[r].count(c)) {
            // Destroy wall at (r, c)
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                it--;
                int ur = *it;
                row_walls[ur].erase(c);
                col_walls[c].erase(ur);
            }

            // Down
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                int dr = *it;
                row_walls[dr].erase(c);
                col_walls[c].erase(dr);
            }

            // Left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                it--;
                int lc = *it;
                col_walls[lc].erase(r);
                row_walls[r].erase(lc);
            }

            // Right
            it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                int rc = *it;
                col_walls[rc].erase(r);
                row_walls[r].erase(rc);
            }
        }
    }
    
    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << '\n';
    
    return 0;
}