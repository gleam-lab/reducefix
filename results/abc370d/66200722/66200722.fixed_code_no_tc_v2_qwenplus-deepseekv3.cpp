#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h);
    vector<set<int>> col_walls(w);
    long long total_walls = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (row_walls[r].count(c)) {
            // Already destroyed, check four directions
            // Up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                row_walls[*it].insert(c);
                total_walls--;
            }
            // Down
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                row_walls[*it].insert(c);
                total_walls--;
            }
            // Left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                col_walls[*it].insert(r);
                total_walls--;
            }
            // Right
            it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                col_walls[*it].insert(r);
                total_walls--;
            }
        } else {
            // Destroy current cell
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            total_walls--;
        }
    }
    
    cout << total_walls << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}