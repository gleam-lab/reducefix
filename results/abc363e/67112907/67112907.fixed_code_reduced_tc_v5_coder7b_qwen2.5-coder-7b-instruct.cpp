#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int h, int n, int m) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] <= h && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] <= h && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<int> levels(k);
    for (int i = 0; i < k; ++i) {
        cin >> levels[i];
    }
    
    sort(levels.begin(), levels.end());
    
    vector<int> results(k);
    int total_area = n * m;
    for (int i = 0; i < k; ++i) {
        fill(visited, visited + n, false);
        bfs(levels[i], n, m);
        int submerged_area = 0;
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < m; ++l) {
                if (visited[j][l]) {
                    submerged_area++;
                }
            }
        }
        results[i] = total_area - submerged_area;
    }
    
    for (int i = 0; i < k; ++i) {
        cout << results[i] << '\n';
    }
    
    return 0;
}