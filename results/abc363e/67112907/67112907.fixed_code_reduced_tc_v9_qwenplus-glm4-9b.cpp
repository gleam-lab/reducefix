#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos {
    int y, x;
};

bool operator<(const Pos& a, const Pos& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> a[i][j];

    priority_queue<Pos(), vector<Pos>, greater<Pos>> pq;
    vector<vector<bool>> vis(h, vector<bool>(w, false));

    // Mark the edges of the island as "sunk"
    for (int i = 0; i < h; ++i) {
        vis[i][0] = vis[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        vis[0][j] = vis[h - 1][j] = true;
    }

    // Initialize the priority queue with the edges
    for (int i = 0; i < h; ++i) {
        pq.push({i, 0});
        pq.push({i, w - 1});
        vis[i][0] = vis[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        pq.push({0, j});
        pq.push({h - 1, j});
        vis[0][j] = vis[h - 1][j] = true;
    }

    // Calculate initial area
    int area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!vis[i][j]) {
                area += a[i][j];
            }
        }
    }

    // Process each year
    for (int currentSeaLevel = 0; currentSeaLevel < y; ++currentSeaLevel) {
        vector<vector<bool>> nextVis(h, vector<bool>(w, false));

        while (!pq.empty()) {
            Pos p = pq.top();
            pq.pop();

            for (int db = -1; db <= 1; ++db) {
                for (int dw = -1; dw <= 1; ++dw) {
                    if (db == 0 && dw == 0) continue;
                    int ny = p.y + db, nx = p.x + dw;
                    if (ny < 0 || ny >= h || nx < 0 || nx >= w || nextVis[ny][nx] || a[ny][nx] >= currentSeaLevel) continue;

                    nextVis[ny][nx] = true;
                    pq.push({ny, nx});
                }
            }
        }

        // Calculate new area
        int newArea = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!nextVis[i][j]) {
                    newArea += a[i][j];
                }
            }
        }

        area = newArea;
        cout << area << '\n';
    }

    return 0;
}