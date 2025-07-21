#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<pair<int, int>>> grid(h);
    rep(i, h) rep(j, w) {
        grid[i].insert({i, j});
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        auto &row = grid[r];
        auto &col = grid[c];

        if (row.find({r, c}) != row.end()) {
            row.erase({r, c});
            col.erase({r, c});
        } else {
            // Find the first wall in the row above
            auto iter_up = prev(lower_bound(all(row), {r - 1, c}));
            if (iter_up != row.begin() && (*iter_up).first == r - 1) {
                row.erase(iter_up);
            }
            // Find the first wall in the row below
            auto iter_down = prev(lower_bound(all(row), {r + 1, c}));
            if (iter_down != row.end() && (*iter_down).first == r + 1) {
                row.erase(iter_down);
            }
            // Find the first wall in the column on the left
            auto iter_left = prev(lower_bound(all(col), {r, c - 1}));
            if (iter_left != col.begin() && (*iter_left).second == c - 1) {
                col.erase(iter_left);
            }
            // Find the first wall in the column on the right
            auto iter_right = prev(lower_bound(all(col), {r, c + 1}));
            if (iter_right != col.end() && (*iter_right).second == c + 1) {
                col.erase(iter_right);
            }
        }
    }

    // Count the remaining walls
    int ans = 0;
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}