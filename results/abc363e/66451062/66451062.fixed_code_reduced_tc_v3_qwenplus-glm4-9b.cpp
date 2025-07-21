#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf 1e18
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool in_bounds(int x, int y, int h, int w) {
    return (x >= 0 && x < h && y >= 0 && y < w);
}

int main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int total_area = h * w;
    
    // Priority queue to store cells with their elevation, (row, col)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with the boundary cells and the first sea level
    for (int i = 0; i < h; i++) {
        pq.push({grid[i][0], {i, 0}});
        pq.push({grid[i][w - 1], {i, w - 1}});
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; j++) {
        pq.push({grid[0][j], {0, j}});
        pq.push({grid[h - 1][j], {h - 1, j}});
        visited[0][j] = visited[h - 1][j] = true;
    }

    for (int level = 1; level <= y; level++) {
        int cells_sunk = 0;
        while (!pq.empty() && pq.top().first <= level) {
            auto [elevation, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;
            // Check and sink adjacent cells
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (in_bounds(nx, ny, h, w) && !visited[nx][ny] && grid[nx][ny] <= level) {
                    visited[nx][ny] = true;
                    cells_sunk++;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }
        cout << total_area - cells_sunk << endl;
    }

    return 0;
}