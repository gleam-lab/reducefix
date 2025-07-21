#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row and column, keep a set of wall positions that are still intact
    vector<set<int>> rows(H), cols(W);

    // Initialize all walls to be present
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    // To track if a cell has already been bombed with a bomb that exploded
    vector<vector<bool>> bombed(H, vector<bool>(W, false));

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (bombed[r][c]) {
            // Bomb explodes - destroy nearest walls in four directions
            int pos;

            // Left
            if (!rows[r].empty() && *rows[r].lower_bound(c) != c && rows[r].lower_bound(c) != rows[r].begin()) {
                auto it = rows[r].lower_bound(c);
                if (it != rows[r].begin()) {
                    --it;
                    rows[r].erase(it);
                    cols[*it].erase(r);
                }
            }

            // Right
            if (!rows[r].empty()) {
                auto it = rows[r].lower_bound(c);
                if (*it == c) ++it;
                if (it != rows[r].end()) {
                    rows[r].erase(it);
                    cols[*it].erase(r);
                }
            }

            // Up
            if (!cols[c].empty()) {
                auto it = cols[c].lower_bound(r);
                if (*it == r) ++it;
                if (it != cols[c].end()) {
                    cols[c].erase(it);
                    rows[*it].erase(c);
                }
            }

            // Down
            if (!cols[c].empty() && *cols[c].lower_bound(r) != r && cols[c].lower_bound(r) != cols[c].begin()) {
                auto it = cols[c].lower_bound(r);
                if (it != cols[c].begin()) {
                    --it;
                    cols[c].erase(it);
                    rows[*it].erase(c);
                }
            }
        } else {
            // Destroy wall at this position if it exists
            if (rows[r].find(c) != rows[r].end()) {
                rows[r].erase(c);
                cols[c].erase(r);
            }
        }

        bombed[r][c] = true;
    }

    // Count remaining walls
    long long remaining = 0;
    for (int i = 0; i < H; ++i) {
        remaining += rows[i].size();
    }

    cout << remaining << endl;

    return 0;
}