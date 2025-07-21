#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1), col_walls(W + 1);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall exists at (r,c)
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Try to destroy the nearest walls in four directions
            auto it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].end()) { // Right
                int y = *it;
                row_walls[r].erase(y);
                col_walls[y].erase(r);
            }

            if (it != row_walls[r].begin()) { // Left
                --it;
                int y = *it;
                row_walls[r].erase(y);
                col_walls[y].erase(r);
            }

            auto jt = col_walls[c].lower_bound(r);
            if (jt != col_walls[c].end()) { // Down
                int x = *jt;
                col_walls[c].erase(x);
                row_walls[x].erase(c);
            }

            if (jt != col_walls[c].begin()) { // Up
                --jt;
                int x = *jt;
                col_walls[c].erase(x);
                row_walls[x].erase(c);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << '\n';

    return 0;
}