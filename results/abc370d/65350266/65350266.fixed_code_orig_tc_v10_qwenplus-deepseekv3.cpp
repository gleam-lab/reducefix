#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H), col_walls(W);
    rep(i, H) rep(j, W) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
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
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                it_up--;
                int i = *it_up;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                remaining--;
            }

            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int i = *it_down;
                row_walls[i].erase(c);
                col_walls[c].erase(i);
                remaining--;
            }

            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                it_left--;
                int j = *it_left;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                remaining--;
            }

            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int j = *it_right;
                row_walls[r].erase(j);
                col_walls[j].erase(r);
                remaining--;
            }
        }
    }

    cout << remaining << "\n";
    return 0;
}