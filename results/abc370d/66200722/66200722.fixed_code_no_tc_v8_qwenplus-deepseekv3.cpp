#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> rows(h + 2); // 1-based to h
    vector<set<int>> cols(w + 2); // 1-based to w
    
    // Initialize all cells as having walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    long long remaining = (long long)h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        
        if (rows[r].count(c)) {
            // Remove the wall at (r, c)
            rows[r].erase(c);
            cols[c].erase(r);
            remaining--;
        } else {
            // Find first walls in each direction
            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                --it_up;
                int wall_r = *it_up;
                rows[wall_r].erase(c);
                cols[c].erase(wall_r);
                remaining--;
            }
            // Down
            it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].end()) {
                int wall_r = *it_up;
                rows[wall_r].erase(c);
                cols[c].erase(wall_r);
                remaining--;
            }
            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                --it_left;
                int wall_c = *it_left;
                rows[r].erase(wall_c);
                cols[wall_c].erase(r);
                remaining--;
            }
            // Right
            it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].end()) {
                int wall_c = *it_left;
                rows[r].erase(wall_c);
                cols[wall_c].erase(r);
                remaining--;
            }
        }
    }
    
    cout << remaining << '\n';
    return 0;
}