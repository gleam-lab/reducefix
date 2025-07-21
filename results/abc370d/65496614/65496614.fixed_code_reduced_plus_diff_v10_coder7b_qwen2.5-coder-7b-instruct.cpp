#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<set<int>> rows(h, set<int>());
    vector<set<int>> cols(w, set<int>());

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to zero-based index

        if (!grid[r][c]) {
            // Find the nearest wall above
            auto it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                grid[*it][c] = true;
                rows[*it].insert(c);
                cols[c].insert(*it);
            }

            // Find the nearest wall below
            it = rows[r].upper_bound(c);
            if (it != rows[r].end()) {
                grid[*it][c] = true;
                rows[*it].insert(c);
                cols[c].insert(*it);
            }

            // Find the nearest wall left
            it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                grid[r][*it] = true;
                rows[r].insert(*it);
                cols[*it].insert(r);
            }

            // Find the nearest wall right
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                grid[r][*it] = true;
                rows[r].insert(*it);
                cols[*it].insert(r);
            }
        } else {
            grid[r][c] = false;
            rows[r].erase(c);
            cols[c].erase(r);
        }
    }

    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) {
                ++count;
            }
        }
    }

    cout << count << '\n';
    return 0;
}