#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, vector<vector<bool>>& grid, int n) {
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 8; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (isValid(nx, ny, n) && !grid[nx][ny]) {
                grid[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<vector<bool>> grid(n, vector<bool>(n, false));
    set<pair<long long, long long>> pieces;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        a--, b--;
        pieces.insert({a, b});
        grid[a][b] = true;
        bfs(a, b, grid, n);
    }

    long long emptySquares = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!grid[i][j]) {
                emptySquares++;
            }
        }
    }

    cout << emptySquares << endl;
    return 0;
}