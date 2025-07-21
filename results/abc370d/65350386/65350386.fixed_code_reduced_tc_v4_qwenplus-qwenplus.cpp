#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Each row has a set of columns with walls
    vector<set<int>> row(h);
    // Each column has a set of rows with walls
    vector<set<int>> col(w);

    // Initialize all walls present
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // If there's a wall at (r,c), destroy it
        auto row_it = row[r].find(c);
        if (row_it != row[r].end()) {
            row[r].erase(row_it);
            col[c].erase(r);
        } 
        else {
            // Otherwise, destroy first walls in four directions

            // Up
            auto up_it = col[c].lower_bound(r);
            if (up_it != col[c].begin()) {
                int up_r = *prev(up_it);
                col[c].erase(up_r);
                row[up_r].erase(c);
            }

            // Down
            auto down_it = col[c].lower_bound(r);
            if (down_it != col[c].end()) {
                int down_r = *down_it;
                col[c].erase(down_it);
                row[down_r].erase(c);
            }

            // Left
            auto left_it = row[r].lower_bound(c);
            if (left_it != row[r].begin()) {
                int left_c = *prev(left_it);
                row[r].erase(left_it);
                col[left_c].erase(r);
            }

            // Right
            auto right_it = row[r].lower_bound(c);
            if (right_it != row[r].end()) {
                int right_c = *right_it;
                row[r].erase(right_it);
                col[right_c].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";
    return 0;
}