#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int H, int W, int sea_level) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    
    // Add all cells that are above the current sea level to the queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > sea_level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    // Perform BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    for (int y = 1; y <= Y; ++y) {
        bfs(H, W, y);
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}