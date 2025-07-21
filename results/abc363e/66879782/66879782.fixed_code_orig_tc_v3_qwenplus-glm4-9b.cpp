#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1002;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void processYear(int year) {
    queue<pair<int, int>> q;
    // Initialize the queue with all border cells or cells that already sank before this year
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || visited[i][j] && grid[i][j] <= year) {
                q.push({i, j});
            }
        }
    }

    // Process the queue
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // If this cell is already visited, skip it
        if (visited[x][y]) continue;

        // Mark this cell as visited
        visited[x][y] = true;

        // Check all adjacent cells
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;
                // Add adjacent cells to the queue if they are not visited and also are going to sink
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= year) {
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // Initialize the visited grid
    memset(visited, false, sizeof(visited));

    // Each year, process the sinking cells
    for (int y = 1; y <= Y; ++y) {
        processYear(y);
    }

    // Calculate the remaining area
    int remainingArea = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                remainingArea++;
            }
        }
    }

    cout << remainingArea << endl;

    return 0;
}