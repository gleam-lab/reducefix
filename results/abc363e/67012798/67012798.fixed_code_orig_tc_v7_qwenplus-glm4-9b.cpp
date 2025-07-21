#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> island(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Initialize the island with elevations and mark the sea sections
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> island[i][j];
        }
    }
    
    // Find the Sections that are originally next to the sea and mark them
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (island[i][j] == 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int remainingArea = 0;
    
    // Simulate the rise in sea level
    for (int seaLevel = 1; seaLevel <= Y; ++seaLevel) {
        queue<pair<int, int>> newQ;
        remainingArea = 0;  // Reset the remaining area at each sea level increase

        // Check all sections adjacent to the sea
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Process adjacent sections
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    continue;
                }
                if (island[nx][ny] > seaLevel) {
                    remainingArea++;  // Current section above sea level
                    visited[nx][ny] = true;
                    newQ.push({nx, ny});
                }
            }
        }
        
        // Move to the next sea level
        q = newQ;
    }
    
    // Output the remaining area after Y years
    for (int i = 0; i < Y; ++i) {
        cout << remainingArea << endl;
    }
    
    return 0;
}