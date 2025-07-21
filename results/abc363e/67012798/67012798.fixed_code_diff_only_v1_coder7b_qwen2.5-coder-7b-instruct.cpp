#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int targetLevel, int& count) {
    queue<pair<int, int>> q;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (!visited[i][j] && A[i][j] > targetLevel) {
                q.push({i, j});
                visited[i][j] = true;
                ++count;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && !visited[nx][ny] && A[nx][ny] > targetLevel) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                ++count;
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
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int maxLevel = *max_element(A.begin(), A.end());

    for (int level = 1; level <= Y; ++level) {
        int remainingArea = H * W;
        bfs(A, visited, level, remainingArea);
        cout << remainingArea << '\n';
    }

    return 0;
}