#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

const int MAXN = 4e5 + 5;

vector<Point> directions = {
    {0, -1}, // left
    {0, 1},  // right
    {-1, 0}, // up
    {1, 0}   // down
};

int H, W, Q;
vector<vector<bool>> grid(MAXN, vector<bool>(MAXN, true));
int wallCount = 0;

void destroyWalls(int r, int c, int dr, int dc) {
    queue<Point> q;
    q.push({r, c});
    grid[r][c] = false;
    wallCount--;
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        for (Point dir : directions) {
            int nx = current.x + dr * dir.x;
            int ny = current.y + dc * dir.y;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || !grid[nx][ny]) continue;
            if (ny + dc > 0 && ny + dc < W && grid[nx][ny] && !grid[nx][ny + dc]) {
                q.push({nx, ny});
                grid[nx][ny] = false;
                wallCount--;
            }
            if (nx + dr > 0 && nx + dr < H && grid[nx][ny] && !grid[nx + dr][ny]) {
                q.push({nx, ny});
                grid[nx][ny] = false;
                wallCount--;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
            if (grid[i][j]) wallCount++;
        }
    }
    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        if (!grid[r - 1][c - 1]) {
            destroyWalls(r - 1, c - 1, 0, 0);
        }
    }
    cout << wallCount << endl;
    return 0;
}