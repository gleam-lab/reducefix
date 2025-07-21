#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int level, int& remainingArea, int H, int W) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                remainingArea--;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] > level && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                remainingArea--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int maxLevel = *max_element(A.begin(), A.end());
    int remainingArea = H * W;

    for (int level = 1; level <= maxLevel; ++level) {
        bfs(A, visited, level, remainingArea, H, W);
        if (remainingArea == 0) break;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << remainingArea << '\n';
    }

    return 0;
}