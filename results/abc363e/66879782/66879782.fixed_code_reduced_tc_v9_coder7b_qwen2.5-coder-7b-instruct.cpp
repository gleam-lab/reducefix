#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

struct Cell {
    int x, y, height;
    Cell(int _x, int _y, int _height) : x(_x), y(_y), height(_height) {}
    bool operator<(const Cell& other) const { return height > other.height; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Read the heights
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    // Priority queue for BFS
    priority_queue<Cell> pq;
    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};

    // Initialize the queue with cells that are below or equal to the initial sea level
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (height[i][j] <= 1) {
                pq.push(Cell(i, j, height[i][j]));
                visited[i][j] = true;
            }
        }
    }

    vector<int> result(y + 1, 0);

    for (int k = 2; k <= y; ++k) {
        // Process all cells in the queue for the current sea level
        while (!pq.empty() && pq.top().height <= k) {
            Cell curr = pq.top(); pq.pop();
            int x = curr.x, y = curr.y, h = curr.height;

            // Sink the current cell and mark it as visited
            height[x][y] = k;

            // Check and sink neighboring cells
            for (int d = 0; d < 4; ++d) {
                int nx = x + di[d], ny = y + dj[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && height[nx][ny] <= k) {
                    pq.push(Cell(nx, ny, height[nx][ny]));
                    visited[nx][ny] = true;
                }
            }
        }

        // Count the remaining area above the current sea level
        result[k] = h * w - pq.size();
    }

    // Print the results for each sea level
    for (int k = 2; k <= y; ++k) {
        cout << result[k] << '\n';
    }

    return 0;
}