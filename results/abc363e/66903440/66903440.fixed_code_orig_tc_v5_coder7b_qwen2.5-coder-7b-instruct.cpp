#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int n, m, k;

void bfs(int x, int y) {
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) + abs(j) == 1) {
                    int nx = p.first + i;
                    int ny = p.second + j;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] <= k) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (!visited[j][l]) {
                    count++;
                }
            }
        }
        cout << count << "\n";
        fill(visited.begin(), visited.end(), vector<bool>(m, false));
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (grid[j][l] > i) {
                    bfs(j, l);
                }
            }
        }
    }

    return 0;
}