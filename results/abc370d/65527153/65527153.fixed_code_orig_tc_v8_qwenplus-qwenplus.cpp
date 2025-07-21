#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);

    // Initialize all walls present
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    auto destroy = [&](int r, int c) {
        row_walls[r].erase(c);
        col_walls[c].erase(r);
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].find(c) == row_walls[r].end()) {
            // Already destroyed, so try to destroy neighbors

            // Left
            {
                auto it = row_walls[r].lower_bound(c);
                if (it != row_walls[r].begin()) {
                    --it;
                    destroy(r, *it);
                }
            }

            // Right
            {
                auto it = row_walls[r].lower_bound(c);
                if (it != row_walls[r].end() && *it != c)
                    destroy(r, *it);
            }

            // Up
            {
                auto it = col_walls[c].lower_bound(r);
                if (it != col_walls[c].begin()) {
                    --it;
                    destroy(*it, c);
                }
            }

            // Down
            {
                auto it = col_walls[c].lower_bound(r);
                if (it != col_walls[c].end() && *it != r)
                    destroy(*it, c);
            }
        } else {
            // Current cell has a wall, destroy it
            destroy(r, c);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i)
        ans += row_walls[i].size();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    while (T--)
        solve();

    return 0;
}