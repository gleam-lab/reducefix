#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Pair {
    int x, y;
};

struct Compare {
    bool operator()(Pair a, Pair b) {
        return a.x < b.x;
    }
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<Pair, vector<Pair>, Compare> pq;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Read the initial heights and populate the priority queue for the edges
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], i, j});
            }
        }
    }

    // Perform the flood fill algorithm to determine the minimum sink height
    while (!pq.empty()) {
        Pair current = pq.top();
        pq.pop();
        int current_height = current.x;
        int r = current.y;
        int c = current.z;
        if (sink[r][c] < current_height) continue;

        for (auto &dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            int new_height = min(height[nr][nc], current_height);
            if (sink[nr][nc] > new_height) {
                sink[nr][nc] = new_height;
                pq.push({new_height, nr, nc});
            }
        }
    }

    // Calculate the initial area above the sea level
    vector<int> prefix_sum(y + 1, 0);
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            if (sink[r][c] <= y) {
                prefix_sum[sink[r][c]]++;
            }
        }
    }

    // Calculate the area of the island above sea level for each year
    for (int i = 1; i <= y; ++i) {
        cout << h * w - prefix_sum[i] << '\n';
    }

    return 0;
}