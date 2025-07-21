#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& visited, int sea_level, int& remaining_area) {
    queue<pair<int, int>> q;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if (A[i][j] > sea_level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                remaining_area--;
            }
        }
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < A.size() && ny >= 0 && ny < A[0].size() && A[nx][ny] > sea_level && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                remaining_area--;
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
    int max_height = *max_element(A.begin(), A.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return *max_element(v1.begin(), v1.end()) < *max_element(v2.begin(), v2.end());
    })[0];

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        int remaining_area = H * W;
        bfs(A, visited, sea_level, remaining_area);
        cout << remaining_area << '\n';
    }

    return 0;
}