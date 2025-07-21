#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];

void bfs(int sea_level, int &remaining_area) {
    queue<pair<int, int>> q;
    bool visited[MAXN][MAXN] = {false};
    
    // Collect all boundary cells that are above the sea level
    for (int i = 0; i < H; ++i) {
        if (A[i][0] > sea_level) q.emplace(i, 0), visited[i][0] = true;
        if (A[i][W-1] > sea_level) q.emplace(i, W-1), visited[i][W-1] = true;
    }
    for (int j = 1; j < W-1; ++j) {
        if (A[0][j] > sea_level) q.emplace(0, j), visited[0][j] = true;
        if (A[H-1][j] > sea_level) q.emplace(H-1, j), visited[H-1][j] = true;
    }

    // Perform BFS to mark all connected cells above the sea level
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        remaining_area--;
        
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc] && A[nr][nc] > sea_level) {
                visited[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    vector<int> result(Y);
    int remaining_area = H * W;
    
    // For each sea level from 1 to Y, calculate the remaining area
    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        bfs(sea_level, remaining_area);
        result[Y-sea_level] = remaining_area;
    }

    // Output the results in reverse order
    for (int i = 0; i < Y; ++i)
        cout << result[i] << "\n";

    return 0;
}