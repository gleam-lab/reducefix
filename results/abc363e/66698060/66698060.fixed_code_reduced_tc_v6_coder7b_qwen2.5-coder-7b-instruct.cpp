#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1010;

vector<vector<int>> grid(MAXN, vector<int>(MAXN));
queue<pair<int, int>> q;
bool visited[MAXN][MAXN];

void bfs(int n, int m, int sea_level) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) == 1) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] <= sea_level) {
                        visited[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, y;
    cin >> n >> m >> y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int year = 1; year <= y; ++year) {
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> initial_q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] <= year) {
                    visited[i][j] = true;
                    initial_q.emplace(i, j);
                }
            }
        }

        bfs(n, m, year);

        int remaining_area = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    ++remaining_area;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}