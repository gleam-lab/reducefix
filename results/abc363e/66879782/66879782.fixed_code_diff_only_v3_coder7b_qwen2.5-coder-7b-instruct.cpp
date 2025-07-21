#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, int target) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];

            if (nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size()) continue;
            if (visited[nx][ny]) continue;
            if (heights[nx][ny] > target) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> heights(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> heights[i][j];
        }
    }

    vector<int> result(y + 1, 0);

    for (int level = 1; level <= y; ++level) {
        fill(all(visited), false);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && heights[i][j] <= level) {
                    bfs(heights, visited, i, j, level);
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (visited[i][j]) {
                    result[level]++;
                }
            }
        }
    }

    for (int i = y; i >= 1; --i) {
        result[i] -= result[i + 1];
    }

    for (int i = 1; i <= y; ++i) {
        cout << result[i] * result[i] << endl;
    }

    return 0;
}