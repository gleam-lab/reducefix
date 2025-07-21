#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<int>> grid(h, vector<int>(w, 1));
    set<pair<int, int>> row[h], col[w];
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[i].insert({j, i});
            col[j].insert({i, j});
        }
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if (grid[r][c] == 0) continue;
        
        grid[r][c] = 0;
        row[r].erase(row[r].find({c, r}));
        col[c].erase(col[c].find({r, c}));
        
        auto it = row[r].lower_bound({c, r});
        if (it != row[r].begin()) {
            --it;
            int prev_c = (*it).first, prev_r = (*it).second;
            if (prev_c < c) {
                row[r].erase(it);
                col[prev_c].erase(prev_r);
            }
        }
        
        it = row[r].upper_bound({c, r});
        if (it != row[r].end()) {
            int next_c = (*it).first, next_r = (*it).second;
            if (next_c > c) {
                row[r].erase(it);
                col[next_c].erase(next_r);
            }
        }
        
        it = col[c].lower_bound({r, c});
        if (it != col[c].begin()) {
            --it;
            int prev_r = (*it).first, prev_c = (*it).second;
            if (prev_r < r) {
                col[c].erase(it);
                row[prev_r].erase(prev_c);
            }
        }
        
        it = col[c].upper_bound({r, c});
        if (it != col[c].end()) {
            int next_r = (*it).first, next_c = (*it).second;
            if (next_r > r) {
                col[c].erase(it);
                row[next_r].erase(next_c);
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
    
    return 0;
}