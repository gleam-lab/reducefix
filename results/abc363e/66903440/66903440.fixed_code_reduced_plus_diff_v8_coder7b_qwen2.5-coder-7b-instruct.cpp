#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector<vector<int>> grid(MAXN, vector<int>(MAXN));
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN));

struct Cell {
    int x, y, h;
};

bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(int n, int m, int targetHeight) {
    queue<Cell> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] <= targetHeight) {
                visited[i][j] = true;
                q.push({i, j, grid[i][j]});
            }
        }
    }

    vector<vector<bool>> updatedVisited(MAXN, vector<bool>(MAXN, false));
    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int cx = front.x, cy = front.y, ch = front.h;
        updatedVisited[cx][cy] = true;

        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (isValid(nx, ny, n, m) && !updatedVisited[nx][ny] && grid[nx][ny] <= targetHeight) {
                updatedVisited[nx][ny] = true;
                q.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (updatedVisited[i][j]) {
                visited[i][j] = true;
            } else {
                visited[i][j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<int> heights;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            heights.push_back(grid[i][j]);
        }
    }
    
    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());
    
    for (int t = 0; t < Y; ++t) {
        bfs(H, W, heights[t]);
        int remainingArea = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (visited[i][j]) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }
    
    return 0;
}