#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);

    // Initialize all cells to have walls
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

        // Check if the cell has a wall
        auto it = rows[r].find(c);
        if (it != rows[r].end()) {
            // Wall exists, remove it
            rows[r].erase(it);
            cols[c].erase(r);
        } else {
            // Wall does not exist, find nearest walls in four directions
            // Up
            auto cit_up = cols[c].lower_bound(r);
            if (cit_up != cols[c].begin()) {
                cit_up--;
                int up_r = *cit_up;
                rows[up_r].erase(c);
                cols[c].erase(up_r);
            }

            // Down
            auto cit_down = cols[c].lower_bound(r);
            if (cit_down != cols[c].end()) {
                int down_r = *cit_down;
                rows[down_r].erase(c);
                cols[c].erase(down_r);
            }

            // Left
            auto rit_left = rows[r].lower_bound(c);
            if (rit_left != rows[r].begin()) {
                rit_left--;
                int left_c = *rit_left;
                cols[left_c].erase(r);
                rows[r].erase(left_c);
            }

            // Right
            auto rit_right = rows[r].lower_bound(c);
            if (rit_right != rows[r].end()) {
                int right_c = *rit_right;
                cols[right_c].erase(r);
                rows[r].erase(right_c);
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