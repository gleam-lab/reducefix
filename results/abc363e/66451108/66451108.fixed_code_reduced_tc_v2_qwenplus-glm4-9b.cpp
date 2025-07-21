#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1001
#define MOD 1000000007

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    
    // Read the grid
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    int totalArea = h * w;
    queue<pair<int, int>> q;

    // Initialize the queue with all the sections adjacent to the sea
    for (int i = 0; i < h; ++i) {
        q.push({i, 0});
        q.push({i, w - 1});
        visited[i][0] = visited[i][w - 1] = true;
        totalArea -= 2;
    }
    
    for (int j = 1; j < w - 1; ++j) {
        q.push({0, j});
        q.push({h - 1, j});
        visited[0][j] = visited[h - 1][j] = true;
        totalArea -= 2;
    }

    // Process the sinking
    for (int year = 1; year <= y; ++year) {
        int sunk = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (visited[nx][ny] || grid[nx][ny] < year + 1) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
                sunk++;
            }
        }

        cout << max(totalArea - sunk, 0) << endl;
    }

    return 0;
}