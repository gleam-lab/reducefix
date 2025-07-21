#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_sets(h), col_sets(w);
    
    // Initialize each cell to have a wall
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_sets[i].insert(j);
            col_sets[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there is a wall at the current position
        if (row_sets[r].count(c)) {
            // Directly destroy the wall at this position
            row_sets[r].erase(c);
            col_sets[c].erase(r);
        } else {
            // Try to destroy walls in four directions

            // Down direction (in column c, greater than r)
            auto down_it = col_sets[c].lower_bound(r);
            if (down_it != col_sets[c].end()) {
                int target_r = *down_it;
                row_sets[target_r].erase(c);
                col_sets[c].erase(down_it);
            }

            // Up direction (in column c, less than r)
            down_it = col_sets[c].lower_bound(r);
            if (down_it != col_sets[c].begin()) {
                --down_it;
                int target_r = *down_it;
                row_sets[target_r].erase(c);
                col_sets[c].erase(down_it);
            }

            // Right direction (in row r, greater than c)
            auto right_it = row_sets[r].lower_bound(c);
            if (right_it != row_sets[r].end()) {
                int target_c = *right_it;
                col_sets[target_c].erase(r);
                row_sets[r].erase(right_it);
            }

            // Left direction (in row r, less than c)
            right_it = row_sets[r].lower_bound(c);
            if (right_it != row_sets[r].begin()) {
                --right_it;
                int target_c = *right_it;
                col_sets[target_c].erase(r);
                row_sets[r].erase(right_it);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_sets[i].size();
    }
    cout << ans << endl;

    return 0;
}