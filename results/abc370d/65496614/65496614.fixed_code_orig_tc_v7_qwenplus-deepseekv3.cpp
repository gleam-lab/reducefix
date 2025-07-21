#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    // Each row's columns that still have walls
    vector<set<int>> rows(h+2);
    // Each column's rows that still have walls
    vector<set<int>> cols(w+2);
    
    // Initialize all positions as having walls
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    // Add boundary markers
    for (int i = 0; i <= h+1; i++) {
        rows[i].insert(0);
        rows[i].insert(w+1);
    }
    for (int j = 0; j <= w+1; j++) {
        cols[j].insert(0);
        cols[j].insert(h+1);
    }
    
    int remaining = h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        auto& row = rows[r];
        auto& col = cols[c];
        
        // Check if current cell has wall
        if (row.count(c)) {
            // Destroy current wall
            row.erase(c);
            col.erase(r);
            remaining--;
        } else {
            // Find first walls in four directions
            
            // Left
            auto it_left = row.lower_bound(c);
            --it_left;
            if (*it_left > 0) {
                col.erase(r);
                rows[r].erase(*it_left);
                remaining--;
            }
            
            // Right
            auto it_right = row.lower_bound(c);
            if (*it_right <= w) {
                col.erase(r);
                rows[r].erase(*it_right);
                remaining--;
            }
            
            // Up
            auto it_up = col.lower_bound(r);
            --it_up;
            if (*it_up > 0) {
                row.erase(c);
                cols[c].erase(*it_up);
                remaining--;
            }
            
            // Down
            auto it_down = col.lower_bound(r);
            if (*it_down <= h) {
                row.erase(c);
                cols[c].erase(*it_down);
                remaining--;
            }
        }
    }
    
    cout << remaining << endl;
    return 0;
}