#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    long long remaining = (long long)H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Check up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int i = *it;
                if (row_walls[i].count(c)) {
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    remaining--;
                }
            }

            // Check down
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                if (row_walls[i].count(c)) {
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    remaining--;
                }
            }

            // Check left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int j = *it;
                if (col_walls[j].count(r)) {
                    col_walls[j].erase(r);
                    row_walls[r].erase(j);
                    remaining--;
                }
            }

            // Check right
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                if (col_walls[j].count(r)) {
                    col_walls[j].erase(r);
                    row_walls[r].erase(j);
                    remaining--;
                }
            }
        }
    }

    cout << remaining << "\n";

    return 0;
}