#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // For each row and column, track the positions of walls using ordered sets
    vector<set<int>> col_walls(w), row_walls(h);
    
    // Initialize walls in all cells
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            col_walls[j].insert(i);
            row_walls[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row_walls[r].count(c)) {
            // Cell has a wall: destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Look up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                it--;
                int y = *it;
                row_walls[y].erase(c);
                col_walls[c].erase(it);
            }

            // Look down
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].end()) {
                int y = *it;
                row_walls[y].erase(c);
                col_walls[c].erase(it);
            }

            // Look left
            auto rit = row_walls[r].lower_bound(c);
            if (rit != row_walls[r].begin()) {
                rit--;
                int x = *rit;
                col_walls[x].erase(r);
                row_walls[r].erase(rit);
            }

            // Look right
            rit = row_walls[r].lower_bound(c);
            if (rit != row_walls[r].end()) {
                int x = *rit;
                col_walls[x].erase(r);
                row_walls[r].erase(rit);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << endl;

    return 0;
}