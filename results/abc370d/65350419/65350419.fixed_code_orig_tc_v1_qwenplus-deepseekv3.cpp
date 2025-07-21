#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Vertical walls (columns) - store row indices for each column
    vector<set<int>> cols(w + 2);  // 1-based indexing
    // Horizontal walls (rows) - store column indices for each row
    vector<set<int>> rows(h + 2);  // 1-based indexing
    
    // Initialize all walls
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cols[j].insert(i);
            rows[i].insert(j);
        }
    }
    
    int remaining = h * w;  // Total walls initially
    
    while(q--) {
        int r, c;
        cin >> r >> c;
        
        if(cols[c].count(r)) {
            // Direct hit - destroy this wall
            cols[c].erase(r);
            rows[r].erase(c);
            remaining--;
        } else {
            // Find first walls in four directions
            // Up
            auto up_it = cols[c].lower_bound(r);
            if(up_it != cols[c].begin()) {
                up_it--;
                int target_r = *up_it;
                cols[c].erase(target_r);
                rows[target_r].erase(c);
                remaining--;
            }
            
            // Down
            auto down_it = cols[c].lower_bound(r);
            if(down_it != cols[c].end()) {
                int target_r = *down_it;
                cols[c].erase(target_r);
                rows[target_r].erase(c);
                remaining--;
            }
            
            // Left
            auto left_it = rows[r].lower_bound(c);
            if(left_it != rows[r].begin()) {
                left_it--;
                int target_c = *left_it;
                rows[r].erase(target_c);
                cols[target_c].erase(r);
                remaining--;
            }
            
            // Right
            auto right_it = rows[r].lower_bound(c);
            if(right_it != rows[r].end()) {
                int target_c = *right_it;
                rows[r].erase(target_c);
                cols[target_c].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << "\n";
    return 0;
}