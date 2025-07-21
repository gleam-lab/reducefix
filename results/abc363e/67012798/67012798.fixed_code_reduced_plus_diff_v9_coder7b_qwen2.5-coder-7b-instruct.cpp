#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& island, int sea_level, int& ans) {
    queue<pair<int, int>> q;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (!island[i][j] && A[i][j] <= sea_level) {
                q.push({i, j});
                island[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        --ans;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && !island[nx][ny] && A[nx][ny] <= sea_level) {
                q.push({nx, ny});
                island[nx][ny] = true;
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

    vector<vector<bool>> island(H, vector<bool>(W, false));
    int total_area = H * W;
    int ans = total_area;

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        bfs(A, island, sea_level, ans);
        cout << ans << '\n';
    }

    return 0;
}