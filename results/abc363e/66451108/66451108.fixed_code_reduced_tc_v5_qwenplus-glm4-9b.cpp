#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int h, w, y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void flood_fill(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > current_level) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;
    int current_level = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Initialize the priority queue with the boundaries of the grid
    for (int i = 0; i < h; ++i) {
        pq.push({grid[i][0], {i, 0}});
        pq.push({grid[i][w - 1], {i, w - 1}});
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (int j = 0; j < w; ++j) {
        pq.push({grid[0][j], {0, j}});
        pq.push({grid[h - 1][j], {h - 1, j}});
        visited[0][j] = visited[h - 1][j] = true;
    }

    // Process each year
    while (y--) {
        int new_sunk_area = 0;
        current_level++;
        while (!pq.empty() && pq.top().first <= current_level) {
            auto [elevation, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            if (!visited[x][y] && grid[x][y] > current_level) {
                visited[x][y] = true;
                flood_fill(x, y);
                new_sunk_area++;
            }
        }
        cout << h * w - new_sunk_area << endl;
    }

    return 0;
}