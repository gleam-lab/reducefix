#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_H = 1000, MAX_W = 1000, MAX_Y = 100000;

int H, W, Y;
int grid[MAX_H][MAX_W];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Priority queue to process cells by sinking order
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.push({grid[i][0], {i, 0}}); // Left boundary
        pq.push({grid[i][W - 1], {i, W - 1}}); // Right boundary
    }
    for (int j = 0; j < W; ++j) {
        pq.push({grid[0][j], {0, j}}); // Top boundary
        pq.push({grid[H - 1][j], {H - 1, j}}); // Bottom boundary
    }
    
    // Process the sinking cells
    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();
        int r = pos.first, c = pos.second;
        
        for (auto& dir : directions) {
            int nr = r + dir.first, nc = c + dir.second;
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] <= height) {
                grid[nr][nc] = height;
                pq.push({height, {nr, nc}});
            }
        }
    }
    
    // Calculate the remaining area above sea level after Y years
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] > Y) {
                remaining_area++;
            }
        }
    }
    
    // Output the result for each year
    for (int y = 1; y <= Y; ++y) {
        cout << remaining_area << '\n';
    }
    
    return 0;
}