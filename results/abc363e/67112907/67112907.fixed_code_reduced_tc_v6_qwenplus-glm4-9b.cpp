#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    
    // Priority queue to sort islands by elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the priority queue with all points
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            pq.push({A[i][j], {i, j}});
        }
    }
    
    // Visited matrix to keep track of processed cells
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Variable to store the area of the island above the sea level
    int remainingArea = H * W;
    
    // Process the priority queue
    while (!pq.empty()) {
        auto [elevation, {x, y}] = pq.top();
        pq.pop();
        
        // If this cell has already been visited, skip it
        if (visited[x][y]) continue;
        
        // Mark this cell as visited
        visited[x][y] = true;
        remainingArea--;
        
        // Mark all adjacent cells as visited if they are below the sea level
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= elevation + 1) {
                    visited[nx][ny] = true;
                    remainingArea--;
                }
            }
        }
    }
    
    // Output the remaining area of the island for each year
    for (int year = 0; year < Y; year++) {
        cout << remainingArea << endl;
    }
    
    return 0;
}