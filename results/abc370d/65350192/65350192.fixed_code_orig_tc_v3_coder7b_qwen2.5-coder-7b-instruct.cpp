#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;

        // Destroy walls above the bomb
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }

        // Destroy walls below the bomb
        for (int i = r + 1; i < h; ++i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }

        // Destroy walls to the left of the bomb
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }

        // Destroy walls to the right of the bomb
        for (int j = c + 1; j < w; ++j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }
    }

    int count = 0;
    for (const auto& row : grid) {
        count += count_if(row.begin(), row.end(), [](bool x){ return !x; });
    }

    cout << count << '\n';
    return 0;
}