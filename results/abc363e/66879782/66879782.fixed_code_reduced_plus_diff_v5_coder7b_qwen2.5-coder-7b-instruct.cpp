#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int n, int m, int h) {
    fill(visited, visited + n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && A[i][j] > h) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] > h) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, y;
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> result(y + 1);
    for (int i = 1; i <= y; ++i) {
        bfs(n, m, i);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    count++;
                }
            }
        }
        result[i] = count;
    }

    for (int i = 1; i <= y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}