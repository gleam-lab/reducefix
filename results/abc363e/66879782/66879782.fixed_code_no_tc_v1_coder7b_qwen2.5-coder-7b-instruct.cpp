#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

// Function to perform BFS to determine the area above a certain sea level
void bfs(int n, int m, int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] > sea_level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = u.first + dx[k];
            int y = u.second + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] > sea_level) {
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, y;
    cin >> n >> m >> y;
    
    // Read the grid
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    // Array to store the number of cells above each sea level
    vector<int> result(y + 1, n * m);

    // Iterate over each possible sea level
    for (int i = 1; i <= y; ++i) {
        bfs(n, m, i);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                if (!visited[j][k])
                    --result[i];
        fill(visited, visited + n * m, false);
    }

    // Print the results
    for (int i = 1; i <= y; ++i)
        cout << result[i] << '\n';

    return 0;
}