#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h + 1), col_walls(w + 1);
    
    // Initialize all cells as having walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int remaining = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (row_walls[r].count(c)) {
            // Cell has a wall, destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // Cell is empty, destroy first walls in four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
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
                --it_left;
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