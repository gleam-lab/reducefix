#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9+10;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    int total_area = H * W;
    
    // Find the starting points of the sinking process
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) q.push({i, 0});
        if (!visited[i][W-1]) q.push({i, W-1});
    }
    for (int j = 0; j < W; ++j) {
        if (!visited[0][j]) q.push({0, j});
        if (!visited[H-1][j]) q.push({H-1, j});
    }
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                int ny = y + dy;
                int nx = x + dx;
                
                if (ny >= 0 && nx >= 0 && ny < H && nx < W && !visited[ny][nx] && A[ny][nx] <= A[y][x] + 1) {
                    visited[ny][nx] = true;
                    total_area--;
                    q.push({ny, nx});
                }
            }
        }
    }
    
    for (int i = 0; i < Y; ++i) {
        cout << total_area << endl;
    }
    
    return 0;
}