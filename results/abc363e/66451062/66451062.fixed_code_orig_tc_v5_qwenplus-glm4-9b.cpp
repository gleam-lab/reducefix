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
    
    vector<vector<int>> sea(h, vector<int>(w, 1));
    
    // Initialize the minimum sea level that can be reached at each cell
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sea[i][j] = grid[i][j];
            } else if (grid[i][j] < sea[i-1][j] && grid[i][j] < sea[i+1][j] &&
                       grid[i][j] < sea[i][j-1] && grid[i][j] < sea[i][j+1]) {
                sea[i][j] = grid[i][j];
            } else {
                sea[i][j] = min({sea[i-1][j], sea[i+1][j], sea[i][j-1], sea[i][j+1]} - 1);
            }
        }
    }
    
    priority_queue<pair<int, int>> pq; // Store (elevation, position)
    int remaining_area = 0;
    
    // Initialize the priority queue with edges
    for (int i = 0; i < h; i++) {
        pq.push({grid[i][0], i * w});
        pq.push({grid[i][w - 1], i * w + w - 1});
        remaining_area += grid[i][0] > sea[i][0] ? 1 : 0;
        remaining_area += grid[i][w - 1] > sea[i][w - 1] ? 1 : 0;
    }
    
    for (int j = 1; j < w - 1; j++) {
        pq.push({grid[0][j], j});
        pq.push({grid[h - 1][j], (h - 1) * w + j});
        remaining_area += grid[0][j] > sea[0][j] ? 1 : 0;
        remaining_area += grid[h - 1][j] > sea[h - 1][j] ? 1 : 0;
    }
    
    // Process the queue
    while (!pq.empty()) {
        int el, pos;
        tie(el, pos) = pq.top();
        pq.pop();
        
        int x = pos / w;
        int y = pos % w;
        
        if (el > sea[x][y]) {
            remaining_area -= 1;
            sea[x][y] = el;
            
            if (x > 0) {
                pq.push({grid[x-1][y], (x-1) * w + y});
            }
            if (x < h - 1) {
                pq.push({grid[x+1][y], (x+1) * w + y});
            }
            if (y > 0) {
                pq.push({grid[x][y-1], x * w + y - 1});
            }
            if (y < w - 1) {
                pq.push({grid[x][y+1], x * w + y + 1});
            }
        }
    }
    
    cout << remaining_area << endl;
    
    return 0;
}