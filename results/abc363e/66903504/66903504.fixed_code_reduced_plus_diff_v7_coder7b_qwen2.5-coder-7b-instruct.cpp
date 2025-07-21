#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int start_i, int start_j, int sea_level) {
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    visited[start_i][start_j] = true;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !visited[ni][nj] && grid[ni][nj] <= sea_level) {
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        // Reset visited array for the current sea level
        fill(visited.begin(), visited.end(), vector<bool>(W, false));

        // Start BFS from each cell above the current sea level
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && grid[i][j] > sea_level) {
                    bfs(i, j, sea_level);
                }
            }
        }

        // Count remaining cells above the current sea level
        int remaining_cells = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] > sea_level) {
                    remaining_cells++;
                }
            }
        }

        cout << remaining_cells << endl;
    }

    return 0;
}