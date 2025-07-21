#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];

bool visited[MAXN][MAXN];

void dfs(int x, int y, int sea_level) {
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;
    
    while (!s.empty()) {
        auto [cx, cy] = s.top();
        s.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                s.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    for (int year = 1; year <= Y; ++year) {
        memset(visited, false, sizeof(visited));
        
        for (int i = 0; i < H; ++i) {
            if (!visited[i][0] && A[i][0] <= year) dfs(i, 0, year);
            if (!visited[i][W - 1] && A[i][W - 1] <= year) dfs(i, W - 1, year);
        }
        
        for (int j = 0; j < W; ++j) {
            if (!visited[0][j] && A[0][j] <= year) dfs(0, j, year);
            if (!visited[H - 1][j] && A[H - 1][j] <= year) dfs(H - 1, j, year);
        }
        
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++remaining_area;
                }
            }
        }
        
        cout << remaining_area << '\n';
    }
    
    return 0;
}