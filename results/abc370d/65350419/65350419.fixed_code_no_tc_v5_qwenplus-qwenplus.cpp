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

        // If there's a wall at the bomb position
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up direction
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int u = *it;
                rows[u].erase(c);
                cols[c].erase(it);
            }

            // Down direction
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int d = *it;
                rows[d].erase(c);
                cols[c].erase(it);
            }

            // Left direction
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                int l = *it;
                cols[l].erase(r);
                rows[r].erase(it);
            }

            // Right direction
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int ri = *it;
                cols[ri].erase(r);
                rows[r].erase(it);
            }
        }
    }

    // Count remaining walls
    ll result = 0;
    for (int i = 0; i < h; ++i) {
        result += rows[i].size();
    }
    cout << result << "\n";

    return 0;
}