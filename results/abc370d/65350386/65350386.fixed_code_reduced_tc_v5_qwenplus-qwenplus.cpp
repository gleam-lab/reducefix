#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rows(H), cols(W);

    // Initialize all cells as having walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (cols[c].count(r) == 0) {
            // Bomb at (r,c) already exploded, do directional destruction
            auto& row = rows[r];
            auto& col = cols[c];

            // Up
            {
                auto it = col.lower_bound(r);
                if (it != col.begin()) {
                    --it;
                    int x = *it;
                    cols[c].erase(x);
                    rows[x].erase(c);
                }
            }

            // Down
            {
                auto it = col.lower_bound(r);
                if (it != col.end() && *it == r) ++it;
                if (it != col.end()) {
                    int x = *it;
                    cols[c].erase(x);
                    rows[x].erase(c);
                }
            }

            // Left
            {
                auto it = row.lower_bound(c);
                if (it != row.begin()) {
                    --it;
                    int y = *it;
                    rows[r].erase(y);
                    cols[y].erase(r);
                }
            }

            // Right
            {
                auto it = row.lower_bound(c);
                if (it != row.end() && *it == c) ++it;
                if (it != row.end()) {
                    int y = *it;
                    rows[r].erase(y);
                    cols[y].erase(r);
                }
            }
        } else {
            // Bomb hits a wall directly
            rows[r].erase(c);
            cols[c].erase(r);
        }
    }

    int total = 0;
    for (int i = 0; i < H; ++i)
        total += rows[i].size();

    cout << total << '\n';
    return 0;
}