#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int r, c;
    Point(int r, int c) : r(r), c(c) {}
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> height(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<int>> sink(H, vector<int>(W, 0));

    // Read the heights of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> height[i][j];
        }
    }

    // Priority queue to keep track of sections that will sink
    priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<pair<int, Point>>> pq;

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({height[i][j], Point(i, j)});
            }
        }
    }

    // Directions for adjacent cells
    vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Process the priority queue
    while (!pq.empty()) {
        auto [h, p] = pq.top();
        pq.pop();

        int r = p.r, c = p.c;

        for (auto &dir : directions) {
            int nr = r + dir.first, nc = c + dir.second;
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                visited[nr][nc] = true;
                if (height[nr][nc] <= h) {
                    sink[nr][nc] = min(h, sink[nr][nc]);
                    pq.push({h, Point(nr, nc)});
                }
            }
        }
    }

    // Calculate the area remaining above the sea level
    int total_area = H * W;
    long long result = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            result += (height[i][j] - sink[i][j]) * (height[i][j] - sink[i][j]);
        }
    }
    result = total_area - result;

    // Output the result for each year
    for (int i = 0; i < Y; ++i) {
        cout << result << '\n';
    }

    return 0;
}