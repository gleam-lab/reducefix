#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> tate(h), yoko(w);

    // Initialize the walls
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tate[i].insert(j);
            yoko[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-indexed

        // Place a bomb and destroy the wall at (r, c)
        tate[r].erase(c);
        yoko[c].erase(r);

        // Check and destroy the upper wall
        bool upper_wall_destroyed = false;
        for (auto it = tate[c].lower_bound(r); it != tate[c].end(); ++it) {
            if (*it != r) {
                tate[c].erase(*it);
                yoko[*it].erase(c);
                upper_wall_destroyed = true;
            } else {
                break;
            }
        }

        // Check and destroy the lower wall
        bool lower_wall_destroyed = false;
        for (auto it = tate[c].upper_bound(r); it != tate[c].begin(); --it) {
            if (*it != r) {
                tate[c].erase(*it);
                yoko[*it].erase(c);
                lower_wall_destroyed = true;
            } else {
                break;
            }
        }

        // Check and destroy the left wall
        bool left_wall_destroyed = false;
        for (auto it = yoko[r].lower_bound(c); it != yoko[r].end(); ++it) {
            if (*it != c) {
                yoko[r].erase(*it);
                tate[*it].erase(r);
                left_wall_destroyed = true;
            } else {
                break;
            }
        }

        // Check and destroy the right wall
        bool right_wall_destroyed = false;
        for (auto it = yoko[r].upper_bound(c); it != yoko[r].begin(); --it) {
            if (*it != c) {
                yoko[r].erase(*it);
                tate[*it].erase(r);
                right_wall_destroyed = true;
            } else {
                break;
            }
        }
    }

    // Calculate the remaining number of walls
    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        remaining_walls += tate[i].size();
    }
    for (int j = 0; j < w; j++) {
        remaining_walls += yoko[j].size();
    }

    cout << remaining_walls << endl;
    return 0;
}