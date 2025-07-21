#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> rows(h + 1);
    vector<set<int>> cols(w + 1);

    // Initialize all cells as having walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        // Check if there is already no wall at the given position
        if (rows[r].find(c) == rows[r].end()) {
            // Find the nearest wall above
            auto it_up = rows[r].upper_bound(c);
            if (it_up != rows[r].begin()) {
                --it_up;
                cols[*it_up].erase(r);
            }

            // Find the nearest wall below
            auto it_down = rows[r].lower_bound(c);
            if (it_down != rows[r].end()) {
                cols[*it_down].erase(r);
            }

            // Find the nearest wall left
            auto it_left = cols[c].upper_bound(r);
            if (it_left != cols[c].begin()) {
                --it_left;
                rows[*it_left].erase(c);
            }

            // Find the nearest wall right
            auto it_right = cols[c].lower_bound(r);
            if (it_right != cols[c].end()) {
                rows[*it_right].erase(c);
            }
        } else {
            // Remove the wall at the given position
            rows[r].erase(c);
            cols[c].erase(r);
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    for (const auto& row : rows) {
        remaining_walls += row.size();
    }

    cout << remaining_walls << endl;

    return 0;
}