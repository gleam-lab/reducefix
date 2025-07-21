#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, height;
};

bool operator<(const Point& p1, const Point& p2) {
    return p1.height > p2.height;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Point> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W-1], i, W-1);
        visited[i][0] = true;
        visited[i][W-1] = true;
    }

    for (int i = 1; i < W-1; ++i) {
        pq.emplace(A[0][i], 0, i);
        pq.emplace(A[H-1][i], H-1, i);
        visited[0][i] = true;
        visited[H-1][i] = true;
    }

    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    for (int i = 1; i <= Y; ++i) {
        while (!pq.empty() && pq.top().height <= i) {
            auto [_, y, x] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                pq.emplace(A[ny][nx], ny, nx);
            }
        }
        cout << ans << endl;
    }

    return 0;
}