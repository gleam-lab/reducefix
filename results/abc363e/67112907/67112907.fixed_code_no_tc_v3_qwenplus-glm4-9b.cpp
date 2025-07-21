#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, h;
};

bool operator<(const Point& a, const Point& b) {
    return a.h > b.h; // Use max-heap to pop the highest elevation point
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

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges of the grid
    for (int i = 0; i < H; ++i) {
        pq.push({i, 0, A[i][0]});
        visited[i][0] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({0, j, A[0][j]});
        visited[0][j] = true;
    }
    for (int i = 0; i < H; ++i) {
        pq.push({i, W - 1, A[i][W - 1]});
        visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({H - 1, j, A[H - 1][j]});
        visited[H - 1][j] = true;
    }

    int remaining_area = H * W;
    while (!pq.empty() && Y > 0) {
        Point p = pq.top();
        if (p.h > Y) {
            break; // No more lands will sink in this year
        }
        pq.pop();
        --remaining_area; // This land will sink

        // Try to sink adjacent lands
        for (int d = 0; d < 4; ++d) {
            int nx = p.x + 1;
            int ny = p.y + d % 2;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (A[nx][ny] > Y) {
                    pq.push({nx, ny, A[nx][ny]});
                }
            }
            nx = p.x - 1;
            ny = p.y + (d + 1) % 2;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (A[nx][ny] > Y) {
                    pq.push({nx, ny, A[nx][ny]});
                }
            }
        }

        Y--;
    }

    for (int i = 0; i < Y; ++i) {
        cout << remaining_area << '\n'; // Output the result for each year
    }

    return 0;
}