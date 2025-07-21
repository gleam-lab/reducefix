#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> A(h, vector<int>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    queue<pair<int, int>> q;
    int area = h * w;

    // Initialize the queue with edge cells that will sink in year 1
    for (int i = 0; i < h; ++i) {
        if (!vis[i][0]) q.push({i, 0});
        if (!vis[i][w - 1]) q.push({i, w - 1});
    }
    for (int j = 1; j < w - 1; ++j) {
        if (!vis[0][j]) q.push({0, j});
        if (!vis[h - 1][j]) q.push({h - 1, j});
    }

    // Process the queue for Y years
    for (int year = 1; year <= y; ++year) {
        while (!q.empty()) {
            auto cell = q.front(); q.pop();
            int x = cell.first, y = cell.second;
            vis[x][y] = true;
            area--;

            // Check and add adjacent cells to the queue
            if (x > 0 && !vis[x - 1][y]) {
                q.push({x - 1, y});
            }
            if (x < h - 1 && !vis[x + 1][y]) {
                q.push({x + 1, y});
            }
            if (y > 0 && !vis[x][y - 1]) {
                q.push({x, y - 1});
            }
            if (y < w - 1 && !vis[x][y + 1]) {
                q.push({x, y + 1});
            }
        }
        cout << area << endl;
    }

    return 0;
}