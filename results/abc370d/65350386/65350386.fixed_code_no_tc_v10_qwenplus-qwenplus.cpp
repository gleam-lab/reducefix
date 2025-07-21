#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);

    // Initialize all walls present
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

        // If there's a wall at the current cell
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int destroy_row = *it;
                cols[c].erase(destroy_row);
                rows[destroy_row].erase(c);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int destroy_row = *it;
                cols[c].erase(destroy_row);
                rows[destroy_row].erase(c);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                int destroy_col = *it;
                rows[r].erase(destroy_col);
                cols[destroy_col].erase(r);
            }

            // Right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int destroy_col = *it;
                rows[r].erase(destroy_col);
                cols[destroy_col].erase(r);
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