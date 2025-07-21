#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Each row and column has a set of remaining wall positions
    vector<set<int>> rows(h), cols(w);

    // Initialize all walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    auto removeWall = [&](int r, int c) {
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int up = *it;
                rows[up].erase(c);
                cols[c].erase(it);
            }

            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                int down = *it;
                rows[down].erase(c);
                cols[c].erase(it);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                int left = *it;
                cols[left].erase(r);
                rows[r].erase(it);
            }

            // Right
            it = rows[r].upper_bound(c);
            if (it != rows[r].end()) {
                int right = *it;
                cols[right].erase(r);
                rows[r].erase(it);
            }
        }
    };

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        removeWall(r, c);
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }

    cout << ans << endl;
    return 0;
}