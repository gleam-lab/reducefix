#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 10;
const int MAX_H = 1000;
const int MAX_W = 1000;

void bfs(vector<vector<int>>& A, vector<vector<bool>>& used, int h, int w, int sea_level) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!used[i][j] && A[i][j] <= sea_level) {
                q.push({i, j});
                used[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !used[nx][ny] && A[nx][ny] <= sea_level) {
                q.push({nx, ny});
                used[nx][ny] = true;
            }
        }
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        bfs(A, used, H, W, sea_level);
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!used[i][j]) {
                    ++count;
                }
            }
        }
        cout << count << endl;
        fill(all(used), false);
    }

    return 0;
}