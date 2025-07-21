#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int x, y;
    Pair() : x(0), y(0) {}
    Pair(int a, int b) : x(a), y(b) {}
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    
    // Use a priority queue to keep track of the elevation and position
    priority_queue<pair<int, Pair>, vector<pair<int, Pair>>, greater<pair<int, Pair>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], Pair(i, j)});
                visited[i][j] = true;
            }
        }
    }
    
    int remainingArea = H * W; // Start with the total area of the island
    
    for (int year = 1; year <= Y; year++) {
        while (!pq.empty()) {
            auto [h, p] = pq.top();
            pq.pop();
            
            // If the current height is less than or equal to the sea level, skip
            if (h <= year) continue;
            
            // Check the four adjacent cells
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
            
            for (int k = 0; k < 4; k++) {
                int nx = p.x + dx[k];
                int ny = p.y + dy[k];
                
                // Check boundaries and if the cell has already been visited
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
                
                // If the current cell is also above sea level, add it to the priority queue
                if (A[nx][ny] > year) {
                    pq.push({A[nx][ny], Pair(nx, ny)});
                    visited[nx][ny] = true;
                }
            }
        }
        
        // Calculate the remaining area
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!visited[i][j] && A[i][j] > year) {
                    remainingArea--;
                }
            }
        }
        
        cout << remainingArea << "\n";
    }
    
    return 0;
}