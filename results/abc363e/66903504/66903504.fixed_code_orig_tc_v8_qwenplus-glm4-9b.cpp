#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_Y = 100000;
const int MAX_A = 100000;

int H, W, Y;
vector<vector<int>> elevation(MAX_H, vector<int>(MAX_W));
vector<vector<bool>> sunk(MAX_H, vector<bool>(MAX_W, false));

struct Point {
    int x, y;
};

void simulateSinking() {
    queue<Point> q;
    
    // Start by flooding the edges
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q.push({i, j});
                sunk[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        int currY = elevation[current.x][current.y];
        
        // Check neighbors
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = current.x + dx;
                int ny = current.y + dy;
                
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny] && elevation[nx][ny] <= currY + 1) {
                    sunk[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> elevation[i][j];
        }
    }
    
    simulateSinking();
    
    for (int y = 1; y <= Y; ++y) {
        int remainingArea = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!sunk[i][j]) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }
    
    return 0;
}