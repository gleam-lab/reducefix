#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Each row and column stores the current wall positions as sets
    vector<set<int>> tate(w);
    vector<set<int>> yoko(h);

    // Initialize all cells with walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at (r, c)
        auto col_it = yoko[r].find(c);
        if (col_it != yoko[r].end()) {
            // Destroy the wall at (r, c)
            yoko[r].erase(col_it);
            tate[c].erase(r);
        } else {
            // Try to destroy walls in four directions

            // Up
            auto up = tate[c].lower_bound(r);
            if (up != tate[c].begin()) {
                --up;
                int tmp = *up;
                tate[c].erase(up);
                yoko[tmp].erase(c);
            }

            // Down
            auto down = tate[c].lower_bound(r);
            if (down != tate[c].end()) {
                int tmp = *down;
                tate[c].erase(down);
                yoko[tmp].erase(c);
            }

            // Left
            auto left = yoko[r].lower_bound(c);
            if (left != yoko[r].begin()) {
                --left;
                int tmp = *left;
                yoko[r].erase(left);
                tate[tmp].erase(r);
            }

            // Right
            auto right = yoko[r].lower_bound(c);
            if (right != yoko[r].end()) {
                int tmp = *right;
                yoko[r].erase(right);
                tate[tmp].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += tate[i].size();
    }
    cout << ans << '\n';

    return 0;
}