#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int h, w, y;
int A[MAXN][MAXN];

struct Cell {
    int x, y, height;
    bool operator<(const Cell& other) const {
        return height > other.height;
    }
};

void bfs(int sea_level, int &remaining_area) {
    queue<Cell> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    // Collect all cells that can be reached from the sea level
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (A[i][j] <= sea_level) {
                q.push({i, j, A[i][j]});
                visited[i][j] = true;
            }
        }
    }

    // Perform BFS to mark all reachable cells
    while (!q.empty()) {
        auto [x, y, _] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                q.push({nx, ny, A[nx][ny]});
                visited[nx][ny] = true;
            }
        }
    }

    // Calculate remaining area
    remaining_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> results(y);
    for (int i = 1; i <= y; ++i) {
        bfs(i, results[y - i]);
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}