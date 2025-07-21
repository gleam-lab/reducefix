#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row(w), col(h);
    
    // Initialize all cells with walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        // Check if there's a wall at the bomb position
        if (col[r].count(c)) {
            // Destroy the wall at (r,c)
            col[r].erase(c);
            row[c].erase(r);
        } else {
            // Up
            auto it = row[c].lower_bound(r);
            if (it != row[c].begin()) {
                it--;
                int destroy_row = *it;
                row[c].erase(destroy_row);
                col[destroy_row].erase(c);
            }

            // Down
            it = row[c].lower_bound(r);
            if (it != row[c].end()) {
                int destroy_row = *it;
                row[c].erase(destroy_row);
                col[destroy_row].erase(c);
            }

            // Left
            auto jt = col[r].lower_bound(c);
            if (jt != col[r].begin()) {
                jt--;
                int destroy_col = *jt;
                col[r].erase(destroy_col);
                row[destroy_col].erase(r);
            }

            // Right
            jt = col[r].lower_bound(c);
            if (jt != col[r].end()) {
                int destroy_col = *jt;
                col[r].erase(destroy_col);
                row[destroy_col].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    
    cout << ans << '\n';
    return 0;
}