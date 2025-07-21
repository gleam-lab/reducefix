#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H), col_walls(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row_walls[r].find(c) != row_walls[r].end()) {
            // Wall exists at (r,c)
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Look in four directions

            // Up and Down
            auto& col_set = col_walls[c];
            auto it_down = col_set.lower_bound(r);
            if (it_down != col_set.end()) {
                int y = *it_down;
                row_walls[y].erase(c);
                col_set.erase(it_down);
            }

            auto it_up = col_set.lower_bound(r);
            if (it_up != col_set.begin()) {
                --it_up;
                int y = *it_up;
                row_walls[y].erase(c);
                col_set.erase(it_up);
            }

            // Left and Right
            auto& row_set = row_walls[r];
            auto it_right = row_set.lower_bound(c);
            if (it_right != row_set.end()) {
                int x = *it_right;
                col_walls[x].erase(r);
                row_set.erase(it_right);
            }

            auto it_left = row_set.lower_bound(c);
            if (it_left != row_set.begin()) {
                --it_left;
                int x = *it_left;
                col_walls[x].erase(r);
                row_set.erase(it_left);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < H; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << '\n';

    return 0;
}