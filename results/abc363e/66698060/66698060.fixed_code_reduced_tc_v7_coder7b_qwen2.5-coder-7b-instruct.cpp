#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));

void bfs(int n, int m, int x, int y, int sea_level) {
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = -1; // Mark as visited
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] <= sea_level) {
                q.push({nx, ny});
                grid[nx][ny] = -1; // Mark as visited
            }
        }
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    
    for (int year = 1; year <= y; ++year) {
        int count = 0;
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > year) {
                    bfs(h, w, i, j, year);
                }
            }
        }
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] != -1) {
                    ++count;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}