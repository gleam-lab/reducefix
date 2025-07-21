#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (grid[r][c] == 0) continue;

        grid[r][c] = 0;

        // Check up
        for (int i = r-1; i >= 0 && grid[i][c]; --i) grid[i][c] = 0;
        
        // Check down
        for (int i = r+1; i < h && grid[i][c]; ++i) grid[i][c] = 0;
        
        // Check left
        for (int j = c-1; j >= 0 && grid[r][j]; --j) grid[r][j] = 0;
        
        // Check right
        for (int j = c+1; j < w && grid[r][j]; ++j) grid[r][j] = 0;
    }

    int count = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            count += grid[i][j];

    cout << count << endl;

    return 0;
}