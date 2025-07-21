#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> A(h, vector<int>(w));
    
    // Reading the elevation grid
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Priority queue to process cells based on their elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the queue with the edges of the grid
    for (int i = 0; i < h; ++i) {
        pq.push({A[i][0], {i, 0}});
        pq.push({A[i][w - 1], {i, w - 1}});
    }
    for (int j = 1; j < w - 1; ++j) {
        pq.push({A[0][j], {0, j}});
        pq.push({A[h - 1][j], {h - 1, j}});
    }
    
    // Visited matrix to keep track of cells that have sunk
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) {
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        visited[0][j] = visited[h - 1][j] = true;
    }
    
    // Variable to keep track of the remaining area
    long long remaining_area = h * w;
    
    // Process the queue for each year
    for (int year = 1; year <= y; ++year) {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();
        int elevation = top.first;
        
        // Process all cells that are about to sink
        while (!pq.empty() && pq.top().first <= elevation) {
            top = pq.top();
            pq.pop();
            int r = top.second.first, c = top.second.second;
            
            remaining_area -= 1; // This cell is now under water
            
            // Check and process neighbors
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc] && A[nr][nc] <= elevation) {
                        visited[nr][nc] = true;
                        remaining_area -= 1; // This neighbor is now under water
                        pq.push({A[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        
        // Output the area of the island that remains above sea level
        cout << remaining_area << endl;
    }
    
    return 0;
}