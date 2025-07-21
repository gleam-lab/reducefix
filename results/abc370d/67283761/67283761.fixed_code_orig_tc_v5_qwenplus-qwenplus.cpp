#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    long long remaining = (long long)H * W;

    using Point = pair<int, int>;
    auto hash = [W](const Point& p) { return p.first * W + p.second; };
    unordered_set<long long> bomb_positions;

    // For each direction, we maintain a map from line (row/column) to an ordered set of wall positions
    // Direction 0: up (rows decreasing)
    // Direction 1: down (rows increasing)
    // Direction 2: left (cols decreasing)
    // Direction 3: right (cols increasing)

    // We use sets for each row and column in all 4 directions
    vector<set<int>> row_up(H), row_down(H);
    vector<set<int>> col_left(W), col_right(W);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_up[i].insert(j);
            row_down[i].insert(j);
            col_left[j].insert(i);
            col_right[j].insert(i);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r;
        --c;

        if (!has_wall[r][c]) {
            // Bomb explodes walls in four directions
            // Look up
            auto it = row_up[r].lower_bound(c);
            if (it != row_up[r].begin()) {
                --it;
                int y = *it;
                if (has_wall[r][y]) {
                    has_wall[r][y] = false;
                    row_up[r].erase(it);
                    row_down[r].erase(y);
                    col_left[y].erase(r);
                    col_right[y].erase(r);
                    --remaining;
                }
            }

            // Look down
            it = row_down[r].upper_bound(c);
            if (it != row_down[r].end()) {
                int y = *it;
                if (has_wall[r][y]) {
                    has_wall[r][y] = false;
                    row_up[r].erase(y);
                    row_down[r].erase(it);
                    col_left[y].erase(r);
                    col_right[y].erase(r);
                    --remaining;
                }
            }

            // Look left
            auto it2 = col_left[c].lower_bound(r);
            if (it2 != col_left[c].begin()) {
                --it2;
                int x = *it2;
                if (has_wall[x][c]) {
                    has_wall[x][c] = false;
                    row_up[x].erase(c);
                    row_down[x].erase(c);
                    col_left[c].erase(it2);
                    col_right[c].erase(x);
                    --remaining;
                }
            }

            // Look right
            it2 = col_right[c].upper_bound(r);
            if (it2 != col_right[c].end()) {
                int x = *it2;
                if (has_wall[x][c]) {
                    has_wall[x][c] = false;
                    row_up[x].erase(c);
                    row_down[x].erase(c);
                    col_left[c].erase(x);
                    col_right[c].erase(it2);
                    --remaining;
                }
            }
        } else {
            // Place bomb on wall
            has_wall[r][c] = false;
            --remaining;

            row_up[r].erase(c);
            row_down[r].erase(c);
            col_left[c].erase(r);
            col_right[c].erase(r);
        }
    }

    cout << remaining << endl;

    return 0;
}