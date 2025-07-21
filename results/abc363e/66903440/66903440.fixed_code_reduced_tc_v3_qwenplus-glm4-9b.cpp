#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int x, y;
    Pair(int x, int y) : x(x), y(y) {}
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<Pair> q;
    
    // Initialize the queue with boundary cells and cells that are initially below sea level
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || grid[i][j] <= 0) {
                visited[i][j] = true;
                q.push(Pair(i, j));
            }
        }
    }
    
    vector<int> years(H * W, 0);
    vector<int> directions{-1, 0, 1, 0, -1};
    
    // Process the queue and mark all cells that will sink
    while (!q.empty()) {
        Pair current = q.front();
        q.pop();
        int x = current.x, y = current.y;
        
        for (int k = 0; k < 4; k++) {
            int nx = x + directions[k], ny = y + directions[k + 1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= 0) {
                visited[nx][ny] = true;
                q.push(Pair(nx, ny));
            }
        }
    }
    
    // Calculate the remaining area above sea level
    int remainingArea = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j] && grid[i][j] > 0) {
                remainingArea++;
            }
        }
    }
    
    // Output the remaining area for each year
    for (int y = 0; y < Y; y++) {
        cout << remainingArea << endl;
    }
    
    return 0;
}