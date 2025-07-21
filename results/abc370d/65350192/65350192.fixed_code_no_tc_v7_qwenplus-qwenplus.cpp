#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(w), col(h);

    // Initialize each row and column with all positions having a wall
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

        // Check if there's a wall at the current cell
        if (row[c].count(r)) {
            // Directly destroy the wall at (r, c)
            row[c].erase(r);
            col[r].erase(c);
        } else {
            // For each direction: up, down, left, right

            // Down (increasing row)
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                int destroy_r = *it_down;
                row[c].erase(destroy_r);
                col[destroy_r].erase(c);
            }

            // Up (decreasing row)
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                int destroy_r = *it_up;
                row[c].erase(destroy_r);
                col[destroy_r].erase(c);
            }

            // Right (increasing column)
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                int destroy_c = *it_right;
                col[r].erase(destroy_c);
                row[destroy_c].erase(r);
            }

            // Left (decreasing column)
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                int destroy_c = *it_left;
                col[r].erase(destroy_c);
                row[destroy_c].erase(r);
            }
        }
    }

    // Count remaining walls
    long long ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;

    return 0;
}