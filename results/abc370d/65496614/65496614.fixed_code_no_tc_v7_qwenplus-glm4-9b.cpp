#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vvi grid(h + 2, vi(w + 2, 1)); // 1 for wall, 0 for bomb
    set<int> rowset(w + 2), colset(h + 2);

    for (int i = 0; i <= w; ++i) rowset.insert(i);
    for (int i = 0; i <= h; ++i) colset.insert(i);

    for (int i = 0; i <= h; ++i) rep (j, w + 2) grid[i][j] = 1;
    for (int i = 0; i <= w; ++i) rep (j, h + 2) grid[j][i] = 1;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        // Check if there's a wall at (r, c) and destroy it
        if (grid[r][c] == 1) {
            grid[r][c] = 0; // Place a bomb at (r, c)
            for (int j = (r > 0 ? r - 1 : 0); j <= (r < h ? r + 1 : h); ++j) {
                if (grid[j][c] == 1) grid[j][c] = 0;
            }
            for (int k = (c > 0 ? c - 1 : 0); k <= (c < w ? c + 1 : w); ++k) {
                if (grid[r][k] == 1) grid[r][k] = 0;
            }
        }
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}