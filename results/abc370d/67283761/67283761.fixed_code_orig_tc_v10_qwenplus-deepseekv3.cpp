#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> row_walls(H+2); // 1-based indexing
    vector<set<int>> col_walls(W+2);
    
    // Initialize all walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    int broken = 0;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        // Check if wall exists at (r,c)
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            broken++;
        } else {
            // Check up direction
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int i = *it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                broken++;
            }
            
            // Check down direction
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                broken++;
            }
            
            // Check left direction
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                broken++;
            }
            
            // Check right direction
            it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                broken++;
            }
        }
    }
    
    cout << (H * W - broken) << '\n';
    
    return 0;
}