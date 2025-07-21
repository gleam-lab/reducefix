#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> heights(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> heights[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    set<pair<int, pair<int, int>>> q;
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    auto withinBounds = [&](int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w;
    };

    auto sinkArea = [&](int startHeight) {
        int area = 0;
        queue<pair<int, int>> todo;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && heights[i][j] <= startHeight) {
                    todo.emplace(i, j);
                    visited[i][j] = true;
                    area++;
                }
            }
        }
        while (!todo.empty()) {
            auto [x, y] = todo.front(); todo.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (withinBounds(nx, ny) && !visited[nx][ny] && heights[nx][ny] <= startHeight) {
                    visited[nx][ny] = true;
                    todo.emplace(nx, ny);
                    area++;
                }
            }
        }
        return area;
    };

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) {
                q.insert({heights[i][j], {i, j}});
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        auto [height, pos] = *q.begin();
        q.erase(q.begin());
        int area = sinkArea(height);
        result.push_back(area);
        if (result.size() > y) break;
    }

    for (int i = 0; i < y; ++i) {
        cout << h * w - result[i] << endl;
    }

    return 0;
}