#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, elevation;
    Point(int px, int py, int pe) : x(px), y(py), elevation(pe) {}
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    for (int j = 0; j < W; j++) {
        pq.emplace(0, j, 0, A[0][j]);
        pq.emplace(0, j, W - 1, A[0][W - 1 - j]);
        used[0][j] = 1;
        used[0][W - 1 - j] = 1;
    }
    for (int i = 1; i < H; i++) {
        pq.emplace(i, 0, 0, A[i][0]);
        pq.emplace(i, W - 1, 0, A[i][W - 1]);
        used[i][0] = 1;
        used[i][W - 1] = 1;
    }

    int ans = H * W;
    while (Y--) {
        Point p = pq.top();
        pq.pop();
        int x = p.x, y = p.y, elevation = p.elevation;
        used[x][y] = 1;
        ans--;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !used[nx][ny] && A[nx][ny] <= elevation) {
                pq.emplace(nx, ny, A[nx][ny]);
                used[nx][ny] = 1;
                ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}