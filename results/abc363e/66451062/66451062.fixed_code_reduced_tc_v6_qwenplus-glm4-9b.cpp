#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Directions for checking neighbors: left, right, up, down
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // Priority queue to process cells by their elevation, starting with boundary cells
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    
    // Initialize the priority queue with boundary cells
    for (int i = 0; i < h; i++) {
        q.push({grid[i][0], {i, 0}}); // Left boundary
        q.push({grid[i][w-1], {i, w-1}}); // Right boundary
    }
    for (int j = 0; j < w; j++) {
        q.push({grid[0][j], {0, j}}); // Top boundary
        q.push({grid[h-1][j], {h-1, j}}); // Bottom boundary
    }
    
    // Visited matrix to keep track of visited cells
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    // Process the grid for y years
    for (int level = 1; level <= y; level++) {
        int remainingCells = 0;
        while (!q.empty()) {
            auto current = q.top();
            q.pop();
            int x = current.second.first;
            int y = current.second.second;
            if (visited[x][y]) continue; // Skip already visited cells
            visited[x][y] = true;
            remainingCells++;
            
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (!visited[nx][ny] && grid[nx][ny] <= level) {
                        q.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        cout << remainingCells << endl;
    }
    
    return 0;
}