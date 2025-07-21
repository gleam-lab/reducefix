#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(w), col(h);

    // Initialize each row and column with all indices
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if the wall exists at (r, c)
        if (col[r].count(c)) {
            // Remove the wall at (r, c)
            col[r].erase(c);
            row[c].erase(r);
        } else {
            // Remove first wall in each direction

            // Up
            auto up = row[c].lower_bound(r);
            if (up != row[c].begin()) {
                up--;
                int ur = *up;
                col[ur].erase(c);
                row[c].erase(up);
            }

            // Down
            auto down = row[c].upper_bound(r);
            if (down != row[c].end()) {
                int dr = *down;
                col[dr].erase(c);
                row[c].erase(down);
            }

            // Left
            auto left = col[r].lower_bound(c);
            if (left != col[r].begin()) {
                left--;
                int lc = *left;
                row[lc].erase(r);
                col[r].erase(left);
            }

            // Right
            auto right = col[r].upper_bound(c);
            if (right != col[r].end()) {
                int rc = *right;
                row[rc].erase(r);
                col[r].erase(right);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
    return 0;
}