#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rows(H + 1), cols(W + 1);

    // Initialize with all walls present
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (rows[r].count(c)) {
            // There's a wall here, destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Destroy nearest walls in all 4 directions
            set<int>::iterator it;

            // Right (east)
            it = rows[r].upper_bound(c);
            if (it != rows[r].end()) {
                cols[*it].erase(r);
                rows[r].erase(it);
            }

            // Left (west)
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                cols[*it].erase(r);
                rows[r].erase(it);
            }

            // Down (south)
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                rows[*it].erase(c);
                cols[c].erase(it);
            }

            // Up (north)
            it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                rows[*it].erase(c);
                cols[c].erase(it);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= H; ++i)
        ans += rows[i].size();

    cout << ans << "\n";

    return 0;
}