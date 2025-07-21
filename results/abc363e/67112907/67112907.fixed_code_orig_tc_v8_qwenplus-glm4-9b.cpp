#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;

struct Point {
    int h, x, y;
};

struct Compare {
    bool operator()(const Point& a, const Point& b) {
        return a.h < b.h;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<i32>> A(H, vector<i32>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<Point, vector<Point>, Compare> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = true;
    }
    for (int i = 1; i < W; i++) {
        pq.push({A[0][i], 0, i});
        visited[0][i] = true;
    }
    for (int i = 1; i < H; i++) {
        pq.push({A[i][W - 1], i, W - 1});
        visited[i][W - 1] = true;
    }
    for (int i = 0; i < W - 1; i++) {
        pq.push({A[H - 1][i], H - 1, i});
        visited[H - 1][i] = true;
    }

    int ans = H * W;
    for (int year = 0; year < Y; year++) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h <= year) {
                pq.pop();
                ans--;
                // Process adjacent cells that are not visited
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            pq.push({A[nx][ny], nx, ny});
                        }
                    }
                }
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}