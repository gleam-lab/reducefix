#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void bfs(vector<vector<int>>& height, vector<vector<bool>>& visited, int& count, int sea_level) {
    int h = height.size();
    int w = height[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && height[i][j] > sea_level) {
                q.push({i, j});
                visited[i][j] = true;
                count++;
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + di[k][0];
                        int nc = c + di[k][1];
                        if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc] && height[nr][nc] > sea_level) {
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                            count++;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }
    vector<int> result(y);
    for (int i = 0; i < y; ++i) {
        int count = 0;
        bfs(height, visited, count, i);
        result[i] = h * w - count;
        fill(all(visited), false);
    }
    for (int i = 0; i < y; ++i) {
        cout << result[i] << '\n';
    }
    return 0;
}