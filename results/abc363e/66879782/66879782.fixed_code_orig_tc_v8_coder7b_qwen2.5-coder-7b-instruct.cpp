#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for (int k = 1; k <= y; ++k) {
        vector<vector<bool>> new_visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && height[i][j] <= k) {
                    // Sink this cell and its neighbors
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    new_visited[i][j] = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int d = 0; d < 4; ++d) {
                            int nx = x + dx[d], ny = y + dy[d];
                            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !new_visited[nx][ny] && height[nx][ny] <= k) {
                                new_visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        visited = new_visited;
    }

    vector<int> result(y, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) {
                result[y - 1]++;
            }
        }
    }

    for (int i = y - 2; i >= 0; --i) {
        result[i] = result[i + 1] + (result[i + 1] != result[i]);
    }

    for (int i = 0; i < y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}