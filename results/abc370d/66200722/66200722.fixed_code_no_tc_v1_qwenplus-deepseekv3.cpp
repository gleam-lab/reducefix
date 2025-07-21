#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_walls(h + 2);  // 1-based indexing
    vector<set<int>> col_walls(w + 2);  // 1-based indexing
    
    // Initialize with sentinel values
    for (int i = 1; i <= h; i++) {
        row_walls[i].insert(0);
        row_walls[i].insert(w + 1);
    }
    for (int j = 1; j <= w; j++) {
        col_walls[j].insert(0);
        col_walls[j].insert(h + 1);
    }
    
    long long total_walls = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (row_walls[r].count(c)) {
            // Wall exists at (r,c) - remove it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            total_walls--;
        } else {
            // Find first walls in four directions
            // Right
            auto it = row_walls[r].upper_bound(c);
            int right_wall = *it;
            if (right_wall != w + 1 && !row_walls[r].count(right_wall - 1)) {
                row_walls[r].insert(right_wall);
                col_walls[right_wall].insert(r);
                total_walls++;
            }
            if (right_wall != w + 1) {
                row_walls[r].erase(right_wall);
                col_walls[right_wall].erase(r);
                total_walls--;
            }
            
            // Left
            it = row_walls[r].lower_bound(c);
            it--;
            int left_wall = *it;
            if (left_wall != 0 && !row_walls[r].count(left_wall + 1)) {
                row_walls[r].insert(left_wall);
                col_walls[left_wall].insert(r);
                total_walls++;
            }
            if (left_wall != 0) {
                row_walls[r].erase(left_wall);
                col_walls[left_wall].erase(r);
                total_walls--;
            }
            
            // Down
            it = col_walls[c].upper_bound(r);
            int down_wall = *it;
            if (down_wall != h + 1 && !col_walls[c].count(down_wall - 1)) {
                col_walls[c].insert(down_wall);
                row_walls[down_wall].insert(c);
                total_walls++;
            }
            if (down_wall != h + 1) {
                col_walls[c].erase(down_wall);
                row_walls[down_wall].erase(c);
                total_walls--;
            }
            
            // Up
            it = col_walls[c].lower_bound(r);
            it--;
            int up_wall = *it;
            if (up_wall != 0 && !col_walls[c].count(up_wall + 1)) {
                col_walls[c].insert(up_wall);
                row_walls[up_wall].insert(c);
                total_walls++;
            }
            if (up_wall != 0) {
                col_walls[c].erase(up_wall);
                row_walls[up_wall].erase(c);
                total_walls--;
            }
        }
    }
    
    cout << total_walls << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}