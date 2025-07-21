#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvl = vector<vll>;
using pair = pair<int, int>;
using vpair = vector<pair<int, int>>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;
    vector<string> grid(h, string(w, '1')); // Initialize grid with all walls

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to 0-based index

        if (grid[r][c] == '1') {
            grid[r][c] = '0'; // Destroy the wall at (r, c)
        } else {
            // Destroy walls in all four directions
            // Up
            for (int i = r - 1; i >= 0 && grid[i][c] == '1'; --i)
                grid[i][c] = '0';
            // Down
            for (int i = r + 1; i < h && grid[i][c] == '1'; ++i)
                grid[i][c] = '0';
            // Left
            for (int j = c - 1; j >= 0 && grid[r][j] == '1'; --j)
                grid[r][j] = '0';
            // Right
            for (int j = c + 1; j < w && grid[r][j] == '1'; ++j)
                grid[r][j] = '0';
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (grid[i][j] == '1')
                ++remainingWalls;

    cout << remainingWalls << '\n';
    return 0;
}