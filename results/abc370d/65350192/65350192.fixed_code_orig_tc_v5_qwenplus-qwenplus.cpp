#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // For each row and column, maintain a set of remaining wall positions
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
        if (cols[c].count(r)) {
            // Destroy wall at (r,c)
            cols[c].erase(r);
            rows[r].erase(c);
        } else {
            // Directional destruction: up, down, left, right

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int destroy_r = *it;
                cols[c].erase(it);
                rows[destroy_r].erase(c);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int destroy_r = *it;
                cols[c].erase(it);
                rows[destroy_r].erase(c);
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                int destroy_c = *jt;
                rows[r].erase(jt);
                cols[destroy_c].erase(r);
            }

            // Right
            jt = rows[r].lower_bound(c);
            if (jt != rows[r].end()) {
                int destroy_c = *jt;
                rows[r].erase(jt);
                cols[destroy_c].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += cols[i].size();
    }

    cout << ans << "\n";
    return 0;
}