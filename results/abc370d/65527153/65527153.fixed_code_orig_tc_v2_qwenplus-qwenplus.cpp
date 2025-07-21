#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> rowWalls(H + 1), colWalls(W + 1);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rowWalls[i].insert(j);
            colWalls[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (rowWalls[r].count(c)) {
            // Bomb placed on a wall: destroy it
            rowWalls[r].erase(c);
            colWalls[c].erase(r);
        } else {
            // Bomb placed on empty cell: destroy first walls in four directions

            // Up and Down
            auto& cw = colWalls[c];
            auto it = cw.lower_bound(r);
            if (it != cw.end()) { // down
                int x = *it;
                rowWalls[x].erase(c);
                cw.erase(it);
            }
            if (it != cw.begin()) { // up
                --it;
                int x = *it;
                rowWalls[x].erase(c);
                cw.erase(it);
            }

            // Left and Right
            auto& rw = rowWalls[r];
            it = rw.lower_bound(c);
            if (it != rw.end()) { // right
                int y = *it;
                colWalls[y].erase(r);
                rw.erase(it);
            }
            if (it != rw.begin()) { // left
                --it;
                int y = *it;
                colWalls[y].erase(r);
                rw.erase(it);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= H; ++i)
        ans += rowWalls[i].size();
    cout << ans << "\n";

    return 0;
}