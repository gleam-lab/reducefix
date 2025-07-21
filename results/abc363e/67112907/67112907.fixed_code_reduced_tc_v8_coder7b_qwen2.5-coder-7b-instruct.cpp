#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));
    
    // Initialize the queue with all cells that are not submerged
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > sea_level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    // Perform BFS to mark all reachable cells above the sea level
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int countRemainingArea() {
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j]) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    for (int year = 0; year < Y; ++year) {
        bfs(year);
        cout << countRemainingArea() << '\n';
    }
    
    return 0;
}