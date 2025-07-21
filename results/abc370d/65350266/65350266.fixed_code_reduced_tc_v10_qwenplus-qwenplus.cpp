#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);
    
    // Initialize each cell in its respective row and column
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
            cols[c].erase(r);
        } else {
            // Look up
            auto cit_up = cols[c].lower_bound(r);
            if (cit_up != cols[c].begin()) {
                cit_up--;
                int hit_r = *cit_up;
                rows[hit_r].erase(c);
                cols[c].erase(hit_r);
            }

            // Look down
            auto cit_down = cols[c].lower_bound(r);
            if (cit_down != cols[c].end()) {
                int hit_r = *cit_down;
                rows[hit_r].erase(c);
                cols[c].erase(hit_r);
            }

            // Look left
            auto rit_left = rows[r].lower_bound(c);
            if (rit_left != rows[r].begin()) {
                rit_left--;
                int hit_c = *rit_left;
                cols[hit_c].erase(r);
                rows[r].erase(hit_c);
            }

            // Look right
            auto rit_right = rows[r].lower_bound(c);
            if (rit_right != rows[r].end()) {
                int hit_c = *rit_right;
                cols[hit_c].erase(r);
                rows[r].erase(hit_c);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << "\n";
    return 0;
}