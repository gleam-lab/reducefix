#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Cell {
    int r, c, height;
};

bool operator<(const Cell& a, const Cell& b) {
    return a.height > b.height;
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> elevation(h, vector<int>(w));
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> elevation[i][j];
        }
    }

    // Initialize the priority queue with cells on the border or at sea level
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = elevation[i][j];
                pq.push({i, j, elevation[i][j]});
            }
        }
    }

    vector<int> lastSunk(y + 1, 0);
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();

        if (visited[current.r][current.c]) continue;
        visited[current.r][current.c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = current.r + ((i + 1) % 4) - 1;
            int nc = current.c + (i % 4);

            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

            if (elevation[nr][nc] <= current.height) {
                sink[nr][nc] = min(sink[nr][nc], current.height);
                pq.push({nr, nc, sink[nr][nc]});
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink[i][j] <= y) {
                lastSunk[sink[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= y; ++i) {
        cout << (h * w - lastSunk[i]) << '\n';
    }

    return 0;
}