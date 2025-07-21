#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<bool>> f(h, vector<bool>(w, true));
    cin >> &a[0][0];

    // Mark border cells as sinking
    for (int i = 0; i < h; i++) {
        f[i][0] = f[i][w - 1] = true;
    }
    for (int j = 0; j < w; j++) {
        f[0][j] = f[h - 1][j] = true;
    }

    // Prepare BFS
    vector<queue<pair<int, int>>> q(h * w + 1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                q[a[i][j]].push({i, j});
                f[i][j] = false;
            }
        }
    }

    // Process each year
    for (int y = 1; y <= y; y++) {
        int remaining_area = h * w;
        for (auto& p : q[y]) {
            int i = p.first, j = p.second;
            remaining_area -= f[i][j]; // reduce the remaining area by the number of sinking cells
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                    if (f[ni][nj] && a[ni][nj] >= y) { // only sink if the cell has not sunk yet and is above current sea level
                        f[ni][nj] = false;
                        q[a[ni][nj]].push({ni, nj});
                    }
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}