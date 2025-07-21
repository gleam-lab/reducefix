#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<set<int>>> row(h + 1, vector<set<int>>(w + 1));
    vector<vector<set<int>>> col(w + 1, vector<set<int>>(h + 1));
    vector<vector<bool>> coo(h + 1, vector<bool>(w + 1, true));

    // Initialize row and column sets
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i][j] = {j};
            col[j][i] = {i};
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        set<int>& r_set = row[r][c];
        set<int>& c_set = col[c][r];

        // Check if there's a wall at (r, c)
        if (!r_set.empty()) {
            int wall = *r_set.begin();
            r_set.erase(wall);
            col[wall][r].erase(r);
            coo[r][c] = false;
        } else {
            // Destroy walls in all four directions
            // Up
            for (int i : r_set) {
                if (i < r) {
                    int wall = i;
                    r_set.erase(wall);
                    col[wall][r].erase(r);
                    coo[i][c] = false;
                }
            }
            // Down
            for (int i : r_set) {
                if (i > r) {
                    int wall = i;
                    r_set.erase(wall);
                    col[wall][r].erase(r);
                    coo[i][c] = false;
                }
            }
            // Left
            for (int j : c_set) {
                if (j < c) {
                    int wall = j;
                    c_set.erase(wall);
                    row[r][wall].erase(r);
                    coo[r][j] = false;
                }
            }
            // Right
            for (int j : c_set) {
                if (j > c) {
                    int wall = j;
                    c_set.erase(wall);
                    row[r][wall].erase(r);
                    coo[r][j] = false;
                }
            }
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            remaining_walls += coo[i][j];
        }
    }

    cout << remaining_walls << endl;
    return 0;
}