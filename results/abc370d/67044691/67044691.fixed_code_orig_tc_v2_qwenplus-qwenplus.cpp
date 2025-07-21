#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row(h), col(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        auto it_row = row[r].find(c);
        if (it_row != row[r].end()) {
            // Wall exists, remove it
            row[r].erase(it_row);
            col[c].erase(col[c].find(r));
        } else {
            // Find walls in four directions
            vector<pair<int, int>> destroy;

            // Up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                destroy.push_back({*it, c});
            }

            // Down
            it = col[c].upper_bound(r);
            if (it != col[c].end()) {
                destroy.push_back({*it, c});
            }

            // Left
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                destroy.push_back({r, *it});
            }

            // Right
            it = row[r].upper_bound(c);
            if (it != row[r].end()) {
                destroy.push_back({r, *it});
            }

            // Remove destroyed walls
            for (auto [x, y] : destroy) {
                row[x].erase(y);
                col[y].erase(x);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row[i].size();
    }

    cout << ans << endl;
}