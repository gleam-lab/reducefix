#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    auto bfs = [&](int sea_level) -> int {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && grid[i][j] > sea_level) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int count = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            count++;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > sea_level) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return count;
    };

    for (int i = 1; i <= y; ++i) {
        cout << bfs(i) << '\n';
    }

    return 0;
}