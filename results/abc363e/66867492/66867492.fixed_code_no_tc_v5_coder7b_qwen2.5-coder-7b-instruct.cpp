#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, height;
    Point(int x, int y, int h) : x(x), y(y), height(h) {}
};

bool operator<(const Point& a, const Point& b) {
    return a.height > b.height;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> used(H, vector<bool>(W, false));

    priority_queue<Point> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(i, 0, A[i][0]);
        pq.emplace(i, W - 1, A[i][W - 1]);
        used[i][0] = true;
        used[i][W - 1] = true;
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.emplace(0, j, A[0][j]);
        pq.emplace(H - 1, j, A[H - 1][j]);
        used[0][j] = true;
        used[H - 1][j] = true;
    }

    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().height <= year) {
            auto [x, y, height] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || used[nx][ny]) continue;
                if (chmax(used[nx][ny], true)) {
                    pq.emplace(nx, ny, A[nx][ny]);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}