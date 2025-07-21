#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Cell {
    int h, x, y;
};

bool operator<(const Cell& a, const Cell& b) {
    return a.h > b.h;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Initialize the priority queue with all edges of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && !visited[i][j]) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }
    
    // Process the cells
    while (!pq.empty()) {
        Cell c = pq.top();
        pq.pop();
        
        // If the current height is less than the current year, continue
        if (c.h < Y) continue;
        
        // Process the neighbors
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                int ni = c.x + di, nj = c.y + dj;
                if (ni < 0 || ni >= H || nj < 0 || nj >= W || visited[ni][nj] || ni == c.x && nj == c.y) continue;
                
                // If the neighbor is not visited and has a height less than the current year, add to the queue
                if (A[ni][nj] < Y) {
                    pq.push({A[ni][nj], ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
    }
    
    // Count the remaining cells above sea level after Y years
    int remaining = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] >= Y) {
                remaining++;
            }
        }
    }
    
    cout << remaining << '\n';
    
    return 0;
}