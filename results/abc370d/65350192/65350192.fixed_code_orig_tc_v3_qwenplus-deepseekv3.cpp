#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H), col_walls(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int remaining = H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Check up direction
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int target = *it_up;
                col_walls[c].erase(target);
                row_walls[target].erase(c);
                remaining--;
            }

            // Check down direction
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int target = *it_down;
                col_walls[c].erase(target);
                row_walls[target].erase(c);
                remaining--;
            }

            // Check left direction
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int target = *it_left;
                row_walls[r].erase(target);
                col_walls[target].erase(r);
                remaining--;
            }

            // Check right direction
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int target = *it_right;
                row_walls[r].erase(target);
                col_walls[target].erase(r);
                remaining--;
            }
        }
    }

    cout << remaining << '\n';
    return 0;
}