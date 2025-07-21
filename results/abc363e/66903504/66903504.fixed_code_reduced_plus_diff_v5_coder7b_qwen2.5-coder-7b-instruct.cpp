#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));

struct Point {
    int x, y;
};

void bfs(vector<vector<bool>>& visited, int sea_level) {
    static vector<Point> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<Point> q;
    
    // Collect starting points where elevation is less than or equal to the sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] <= sea_level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    // Perform BFS to mark all connected submerged areas
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (auto& dir : directions) {
            int nx = cx + dir.x, ny = cy + dir.y;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
    
    for (int year = 1; year <= Y; ++year) {
        bfs(visited, year);
        
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }
        
        cout << remaining_area << '\n';
    }
    
    return 0;
}