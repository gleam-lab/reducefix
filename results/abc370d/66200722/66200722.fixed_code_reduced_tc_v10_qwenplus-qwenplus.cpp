#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<map<int, int>> row_map(h), col_map(w);
    int total_walls = h * w;
    vector<bool> bomb_placed(h * w);
    
    auto get_idx = [&](int r, int c) { return r * w + c; };
    
    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        int idx = get_idx(r, c);
        if (!bomb_placed[idx]) {
            bomb_placed[idx] = true;
            total_walls--;
            continue;
        }
        
        // Up
        auto it = row_map[c].lower_bound(r);
        if (it != row_map[c].begin()) {
            --it;
            int ur = *it;
            int uidx = get_idx(ur, c);
            if (!bomb_placed[uidx]) {
                bomb_placed[uidx] = true;
                total_walls--;
            }
        }
        
        // Down
        it = row_map[c].upper_bound(r);
        if (it != row_map[c].end()) {
            int dr = *it;
            int didx = get_idx(dr, c);
            if (!bomb_placed[didx]) {
                bomb_placed[didx] = true;
                total_walls--;
            }
        }
        
        // Left
        auto &row = col_map[r];
        it = row.lower_bound(c);
        if (it != row.begin()) {
            --it;
            int lc = *it;
            int lidx = get_idx(r, lc);
            if (!bomb_placed[lidx]) {
                bomb_placed[lidx] = true;
                total_walls--;
            }
        }
        
        // Right
        it = row.upper_bound(c);
        if (it != row.end()) {
            int rc = *it;
            int ridx = get_idx(r, rc);
            if (!bomb_placed[ridx]) {
                bomb_placed[ridx] = true;
                total_walls--;
            }
        }
    }
    
    cout << total_walls << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}