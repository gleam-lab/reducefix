#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // We'll use sets to efficiently find neighbors
    vector<set<int>> row(H+2);  // for each row, store columns with walls
    vector<set<int>> col(W+2);  // for each column, store rows with walls
    
    // Initialize with all possible walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (row[r].count(c)) {
            // If wall exists at (r,c), destroy it
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Find first walls in four directions
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                row[*it_up].erase(c);
                col[c].erase(it_up);
            }
            
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                row[*it_down].erase(c);
                col[c].erase(it_down);
            }
            
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                col[*it_left].erase(r);
                row[r].erase(it_left);
            }
            
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                col[*it_right].erase(r);
                row[r].erase(it_right);
            }
        }
    }
    
    // Count remaining walls
    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row[i].size();
    }
    
    cout << ans << endl;
    return 0;
}