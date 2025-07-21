#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];

// Function to perform BFS and calculate the area above the sea level
void bfs(int sea_level) {
    queue<pair<int, int>> q;
    bool visited[MAXN][MAXN] = {false};
    
    // Collect all cells that can be reached by the sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] > sea_level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int count = 0;
    // Perform BFS to count all reachable cells
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        
        count++;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            int nx = cell.first + dx[k];
            int ny = cell.second + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    
    // Print the result
    cout << count << endl;
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Process each sea level from 1 to Y
    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        bfs(sea_level);
    }
    
    return 0;
}