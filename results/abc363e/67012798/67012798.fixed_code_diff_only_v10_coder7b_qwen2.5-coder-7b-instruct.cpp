#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int targetHeight) {
    queue<pair<int, int>> q;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (A[i][j] > targetHeight && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && A[nx][ny] > targetHeight && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
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
    vector<int> remainingArea(Y + 1);

    for (int h = 1; h <= Y; ++h) {
        bfs(A, visited, h);
        remainingArea[h] = H * W - count_if(begin(visited), end(visited), [](const auto& v){return accumulate(begin(v), end(v), 0);});
    }

    for (int h = 1; h <= Y; ++h) {
        cout << remainingArea[h] << '\n';
    }

    return 0;
}