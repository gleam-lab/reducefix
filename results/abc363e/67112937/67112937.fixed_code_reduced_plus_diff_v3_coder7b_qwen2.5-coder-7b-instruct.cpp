#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m, y;
queue<pair<int, int>> q;

void bfs(int start_x, int start_y, int sea_level) {
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) != 1) continue; // Only consider vertical/horizontal neighbors
                
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                
                if (A[nx][ny] <= sea_level) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<int> result(y);
    for (int i = 0; i < y; ++i) {
        fill_n(visited[0], sizeof(visited[0]), false);
        int sea_level = i + 1;
        int count = 0;
        
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (A[j][k] > sea_level && !visited[j][k]) {
                    bfs(j, k, sea_level);
                    count++;
                }
            }
        }
        
        result[i] = n * m - count * (count + 1) / 2;
    }
    
    for (int i = 0; i < y; ++i) {
        cout << result[i] << '\n';
    }
    
    return 0;
}