#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int value, x, y;
    Point(int v, int a, int b) : value(v), x(a), y(b) {}
};

struct Compare {
    bool operator()(Point p1, Point p2) const {
        return p1.value < p2.value;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));
    priority_queue<Point, vector<Point>, Compare> pq;

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        pq.push(Point(A[i][0], i, 0));
        pq.push(Point(A[i][W - 1], i, W - 1));
        used[i][0] = used[i][W - 1] = 1;
    }
    for (int j = 0; j < W; ++j) {
        pq.push(Point(A[0][j], 0, j));
        pq.push(Point(A[H - 1][j], H - 1, j));
        used[0][j] = used[H - 1][j] = 1;
    }

    int remaining_area = H * W;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().value <= year) {
            Point current = pq.top();
            pq.pop();
            remaining_area -= 1;

            for (auto& dir : directions) {
                int nx = current.x + dir[0];
                int ny = current.y + dir[1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (used[ny][nx] == 0) {
                    used[ny][nx] = 1;
                    pq.push(Point(A[ny][nx], ny, nx));
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}