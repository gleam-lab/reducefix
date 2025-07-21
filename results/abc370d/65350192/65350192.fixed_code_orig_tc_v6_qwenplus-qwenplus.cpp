#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_sets(h), col_sets(w);
    
    // Initialize sets with all column indices for each row and vice versa
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_sets[i].insert(j);
            col_sets[j].insert(i);
        }
    }
    
    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        // Check if there's a wall at the current position
        if (row_sets[r].count(c)) {
            // Destroy wall at (r,c)
            row_sets[r].erase(c);
            col_sets[c].erase(r);
        } else {
            // Up
            auto it = col_sets[c].lower_bound(r);
            if (it != col_sets[c].end()) {
                int destroy_r = *it;
                row_sets[destroy_r].erase(c);
                col_sets[c].erase(destroy_r);
            }
            
            // Down
            it = col_sets[c].lower_bound(r);
            if (it != col_sets[c].begin()) {
                --it;
                int destroy_r = *it;
                row_sets[destroy_r].erase(c);
                col_sets[c].erase(destroy_r);
            }
            
            // Right
            auto jt = row_sets[r].lower_bound(c);
            if (jt != row_sets[r].end()) {
                int destroy_c = *jt;
                col_sets[destroy_c].erase(r);
                row_sets[r].erase(destroy_c);
            }
            
            // Left
            jt = row_sets[r].lower_bound(c);
            if (jt != row_sets[r].begin()) {
                --jt;
                int destroy_c = *jt;
                col_sets[destroy_c].erase(r);
                row_sets[r].erase(destroy_c);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_sets[i].size();
    }
    
    cout << ans << "\n";
    return 0;
}