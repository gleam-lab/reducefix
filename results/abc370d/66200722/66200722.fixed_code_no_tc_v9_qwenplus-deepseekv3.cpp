#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h), col_walls(w);
    for (int i = 0; i < h; i++) {
        row_walls[i].insert(-1);
        row_walls[i].insert(w);
    }
    for (int j = 0; j < w; j++) {
        col_walls[j].insert(-1);
        col_walls[j].insert(h);
    }
    
    long long ans = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (!row_walls[r].count(c)) {
            // Wall exists - destroy it
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            ans--;
            continue;
        }
        
        // Wall doesn't exist - find first walls in four directions
        // Up
        auto it = col_walls[c].lower_bound(r);
        it--;
        if (*it != -1) {
            if (!row_walls[*it].count(c)) {
                row_walls[*it].insert(c);
                col_walls[c].insert(*it);
                ans--;
            }
        }
        
        // Down
        it = col_walls[c].upper_bound(r);
        if (*it != h) {
            if (!row_walls[*it].count(c)) {
                row_walls[*it].insert(c);
                col_walls[c].insert(*it);
                ans--;
            }
        }
        
        // Left
        it = row_walls[r].lower_bound(c);
        it--;
        if (*it != -1) {
            if (!col_walls[*it].count(r)) {
                col_walls[*it].insert(r);
                row_walls[r].insert(*it);
                ans--;
            }
        }
        
        // Right
        it = row_walls[r].upper_bound(c);
        if (*it != w) {
            if (!col_walls[*it].count(r)) {
                col_walls[*it].insert(r);
                row_walls[r].insert(*it);
                ans--;
            }
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}