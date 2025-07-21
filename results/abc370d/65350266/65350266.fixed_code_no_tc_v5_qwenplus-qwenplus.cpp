#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> rows(h), cols(w);
    
    // Initialize each row and column with all positions having a wall
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

        // Check if the current cell has a wall
        auto it = rows[r].find(c);
        if (it != rows[r].end()) {
            // Wall exists at (r,c), destroy it
            rows[r].erase(it);
            cols[c].erase(cols[c].find(r));
        } else {
            // Wall does not exist, search in four directions
            // Up and Down (column c)
            auto down = cols[c].lower_bound(r);
            if (down != cols[c].end()) {
                int nr = *down;
                rows[nr].erase(rows[nr].find(c));
                cols[c].erase(down);
            }

            auto up = cols[c].lower_bound(r);
            if (up != cols[c].begin()) {
                --up;
                int nr = *up;
                rows[nr].erase(rows[nr].find(c));
                cols[c].erase(up);
            }

            // Left and Right (row r)
            auto right = rows[r].lower_bound(c);
            if (right != rows[r].end()) {
                int nc = *right;
                cols[nc].erase(cols[nc].find(r));
                rows[r].erase(right);
            }

            auto left = rows[r].lower_bound(c);
            if (left != rows[r].begin()) {
                --left;
                int nc = *left;
                cols[nc].erase(cols[nc].find(r));
                rows[r].erase(left);
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