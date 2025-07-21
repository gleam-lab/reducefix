#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Read elevation data
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    // Initialize queue with boundary cells (sea level)
    for (int i = 0; i < H; ++i) {
        q.push({i, 0});
        q.push({i, W - 1});
    }
    for (int j = 0; j < W; ++j) {
        q.push({0, j});
        q.push({H - 1, j});
    }
    
    // Perform BFS to identify all cells that will be submerged
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if (visited[i][j] || grid[i][j] <= Y - 1) continue;
        visited[i][j] = true;
        
        if (i > 0) q.push({i - 1, j});
        if (i < H - 1) q.push({i + 1, j});
        if (j > 0) q.push({i, j - 1});
        if (j < W - 1) q.push({i, j + 1});
    }
    
    // Count the remaining area above sea level
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && grid[i][j] > Y - 1) {
                remaining_area++;
            }
        }
    }
    
    // Output the result for each year
    for (int y = 1; y <= Y; ++y) {
        cout << remaining_area << endl;
    }
    
    return 0;
}