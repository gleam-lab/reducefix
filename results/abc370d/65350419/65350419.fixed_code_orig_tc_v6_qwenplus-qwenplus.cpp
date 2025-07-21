#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Each row and column's wall positions stored in ordered sets
    vector<set<int>> rows(h), cols(w);
    
    // Initially all cells have walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if current cell has a wall
        auto it_col = cols[c].find(r);
        if (it_col != cols[c].end()) {
            // Destroy wall at (r, c)
            cols[c].erase(it_col);
            rows[r].erase(c);
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int up = *it;
                cols[c].erase(it);
                rows[up].erase(c);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int down = *it;
                cols[c].erase(it);
                rows[down].erase(c);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                int left = *it;
                rows[r].erase(it);
                cols[left].erase(r);
            }

            // Right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int right = *it;
                rows[r].erase(it);
                cols[right].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += cols[i].size();
    }
    cout << ans << '\n';

    return 0;
}