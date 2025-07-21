#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> heights(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> heights[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<int>> levels(h, vector<int>(w, INT_MAX));

    queue<pair<int, pair<int, int>>> q;
    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                levels[i][j] = heights[i][j];
                q.emplace(levels[i][j], make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        auto [level, pos] = q.front(); q.pop();
        int i = pos.first, j = pos.second;
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && heights[ni][nj] <= level) {
                levels[ni][nj] = min(level, heights[ni][nj]);
                q.emplace(levels[ni][nj], make_pair(ni, nj));
            }
        }
    }

    vector<int> areas(y + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (levels[i][j] <= y) {
                ++areas[levels[i][j]];
            }
        }
    }

    for (int i = 1; i <= y; ++i) {
        areas[i] += areas[i - 1];
    }

    for (int i = 1; i <= y; ++i) {
        cout << h * w - areas[i] << '\n';
    }

    return 0;
}