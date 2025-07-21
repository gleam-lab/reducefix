#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h + 2), col_walls(w + 2);

    // Initialize all walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int remaining_walls = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall exists at (r, c), destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining_walls--;
        } else {
            // Destroy first walls in four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int up_r = *it_up;
                row_walls[up_r].erase(c);
                col_walls[c].erase(up_r);
                remaining_walls--;
            }
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int down_r = *it_down;
                row_walls[down_r].erase(c);
                col_walls[c].erase(down_r);
                remaining_walls--;
            }
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int left_c = *it_left;
                row_walls[r].erase(left_c);
                col_walls[left_c].erase(r);
                remaining_walls--;
            }
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int right_c = *it_right;
                row_walls[r].erase(right_c);
                col_walls[right_c].erase(r);
                remaining_walls--;
            }
        }
    }

    cout << remaining_walls << "\n";
    return 0;
}