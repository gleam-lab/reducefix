#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);

    // Initialize all cells as having walls
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }

    int remaining = h * w; // Initially all walls are present

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based indexing

        if (row_walls[r].count(c)) {
            // Wall exists at (r, c), destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
        } else {
            // No wall at (r, c), destroy first walls in four directions
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int i = *it_up;
                if (row_walls[i].count(c)) {
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    remaining--;
                }
            }
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int i = *it_down;
                if (row_walls[i].count(c)) {
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    remaining--;
                }
            }
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int j = *it_left;
                if (col_walls[j].count(r)) {
                    col_walls[j].erase(r);
                    row_walls[r].erase(j);
                    remaining--;
                }
            }
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int j = *it_right;
                if (col_walls[j].count(r)) {
                    col_walls[j].erase(r);
                    row_walls[r].erase(j);
                    remaining--;
                }
            }
        }
    }

    cout << remaining << "\n";
    return 0;
}