#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i,n) for(int i = 1; i <= (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

template<typename T>
using vec = vector<T>;
template<typename T>
using vvec = vector<vector<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    const int MAX = max(H, W) + 2;

    // Grid to track walls
    vvb has_wall(H + 2, vb(W + 2, true));

    // For each row, maintain a set of columns with walls
    vector<set<int>> row_map(H + 2);
    // For each column, maintain a set of rows with walls
    vector<set<int>> col_map(W + 2);

    // Initialize sets with all positions having walls
    rep1(i, H) {
        rep1(j, W) {
            row_map[i].insert(j);
            col_map[j].insert(i);
        }
    }

    auto destroy = [&](int r, int c) {
        if (has_wall[r][c]) {
            // Directly remove the wall
            has_wall[r][c] = false;
            row_map[r].erase(c);
            col_map[c].erase(r);
        } else {
            // Find nearest walls in four directions and destroy them
            // Up
            if (!col_map[c].empty() && *col_map[c].rbegin() > r) {
                auto it = col_map[c].lower_bound(r);
                if (it != col_map[c].end()) {
                    int ur = *it;
                    has_wall[ur][c] = false;
                    row_map[ur].erase(c);
                    col_map[c].erase(ur);
                }
            }

            // Down
            if (!col_map[c].empty() && *col_map[c].begin() < r) {
                auto it = col_map[c].lower_bound(r);
                if (it != col_map[c].begin()) {
                    --it;
                    int dr = *it;
                    has_wall[dr][c] = false;
                    row_map[dr].erase(c);
                    col_map[c].erase(dr);
                }
            }

            // Right
            if (!row_map[r].empty() && *row_map[r].rbegin() > c) {
                auto it = row_map[r].lower_bound(c);
                if (it != row_map[r].end()) {
                    int rc = *it;
                    has_wall[r][rc] = false;
                    row_map[r].erase(rc);
                    col_map[rc].erase(r);
                }
            }

            // Left
            if (!row_map[r].empty() && *row_map[r].begin() < c) {
                auto it = row_map[r].lower_bound(c);
                if (it != row_map[r].begin()) {
                    --it;
                    int lc = *it;
                    has_wall[r][lc] = false;
                    row_map[r].erase(lc);
                    col_map[lc].erase(r);
                }
            }
        }
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        destroy(r, c);
    }

    int remaining = 0;
    rep1(i, H) rep1(j, W) remaining += has_wall[i][j];

    cout << remaining << '\n';
    return 0;
}