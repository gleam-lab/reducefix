#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, height;
};

struct Compare {
    bool operator()(const Point& a, const Point& b) {
        return a.height > b.height;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    priority_queue<Point, vector<Point>, Compare> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W - 1], i, W - 1);
        visited[i][0] = true;
        visited[i][W - 1] = true;
    }
    for (int i = 1; i < W - 1; ++i) {
        pq.emplace(A[0][i], 0, i);
        pq.emplace(A[H - 1][i], H - 1, i);
        visited[0][i] = true;
        visited[H - 1][i] = true;
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int ans = H * W;
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().height <= year) {
            auto [height, x, y] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}