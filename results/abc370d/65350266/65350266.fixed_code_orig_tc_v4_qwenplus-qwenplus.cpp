#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Each row and column is represented as a set of available positions
    vector<set<int>> rows(h), cols(w);
    
    // Initialize all walls are present
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
            // Wall exists at (r,c), destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in four directions and destroy the first wall found in each

            // Up and Down (in column c)
            auto &col = cols[c];
            auto downIt = col.lower_bound(r);
            if (downIt != col.end()) {
                int y = *downIt;
                rows[y].erase(c);
                col.erase(downIt);
            }

            auto upIt = col.lower_bound(r);
            if (upIt != col.begin()) {
                --upIt;
                int y = *upIt;
                rows[y].erase(c);
                col.erase(upIt);
            }

            // Left and Right (in row r)
            auto &row = rows[r];
            auto rightIt = row.lower_bound(c);
            if (rightIt != row.end()) {
                int x = *rightIt;
                cols[x].erase(r);
                row.erase(rightIt);
            }

            auto leftIt = row.lower_bound(c);
            if (leftIt != row.begin()) {
                --leftIt;
                int x = *leftIt;
                cols[x].erase(r);
                row.erase(leftIt);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << '\n';

    return 0;
}