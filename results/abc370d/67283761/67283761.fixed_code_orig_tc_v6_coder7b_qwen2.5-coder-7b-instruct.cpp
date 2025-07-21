#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Bomb {
    int x, y, dist;
};

bool isValid(int x, int y, int H, int W) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

void destroyWalls(vector<vector<bool>>& grid, int x, int y, int H, int W) {
    queue<Bomb> q;
    q.push({x, y, 0});
    while (!q.empty()) {
        Bomb cur = q.front();
        q.pop();
        
        // Check all four directions
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals
                
                int nx = cur.x + dx, ny = cur.y + dy;
                int ndist = cur.dist + 1;
                
                if (isValid(nx, ny, H, W) && !grid[nx][ny]) {
                    grid[nx][ny] = true;
                    q.push({nx, ny, ndist});
                }
            }
        }
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    
    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if (!grid[r][c]) {
            grid[r][c] = true;
        } else {
            destroyWalls(grid, r, c, H, W);
        }
    }
    
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!grid[i][j]) {
                ++remainingWalls;
            }
        }
    }
    
    cout << remainingWalls << endl;
    
    return 0;
}