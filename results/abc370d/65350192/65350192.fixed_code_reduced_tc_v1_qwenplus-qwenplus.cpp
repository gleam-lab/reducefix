#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);
    
    // Initialize sets with all wall positions
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

        if (rows[r].count(c)) {
            // Wall exists at the position, remove it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Find walls to destroy in each direction
            // Up and Down (same column)
            auto &col_set = cols[c];
            auto down_it = col_set.lower_bound(r);
            if (down_it != col_set.end()) {  // Down
                int y = *down_it;
                rows[y].erase(c);
                col_set.erase(down_it);
            }

            if (col_set.size() > 0 && *col_set.begin() < r) {  // Up
                auto up_it = col_set.lower_bound(r);
                if (up_it != col_set.begin()) {
                    --up_it;
                    int y = *up_it;
                    rows[y].erase(c);
                    col_set.erase(up_it);
                }
            }

            // Left and Right (same row)
            auto &row_set = rows[r];
            auto right_it = row_set.lower_bound(c);
            if (right_it != row_set.end()) {  // Right
                int x = *right_it;
                cols[x].erase(r);
                row_set.erase(right_it);
            }

            if (row_set.size() > 0 && *row_set.begin() < c) {  // Left
                auto left_it = row_set.lower_bound(c);
                if (left_it != row_set.begin()) {
                    --left_it;
                    int x = *left_it;
                    cols[x].erase(r);
                    row_set.erase(left_it);
                }
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}