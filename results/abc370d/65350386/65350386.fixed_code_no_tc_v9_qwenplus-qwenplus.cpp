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

        // Check if there's a wall at the bomb position
        if (rows[r].count(c)) {
            // Destroy the wall at (r, c)
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Destroy the first wall in each of the four directions

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                int up = *prev(it);
                cols[c].erase(up);
                rows[up].erase(c);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int down = *it;
                cols[c].erase(down);
                rows[down].erase(c);
            }

            // Left
            auto it2 = rows[r].lower_bound(c);
            if (it2 != rows[r].begin()) {
                int left = *prev(it2);
                rows[r].erase(left);
                cols[left].erase(r);
            }

            // Right
            it2 = rows[r].lower_bound(c);
            if (it2 != rows[r].end()) {
                int right = *it2;
                rows[r].erase(right);
                cols[right].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << "\n";

    return 0;
}