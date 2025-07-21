#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int n, int m, int height) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && A[i][j] > height) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] <= height) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, y;
    cin >> n >> m >> y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> result(y);
    for (int h = 1; h <= y; ++h) {
        memset(visited, 0, sizeof(visited));
        bfs(n, m, h);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    count++;
                }
            }
        }
        result[h-1] = count;
    }

    for (int i = 0; i < y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}