#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_ELEVATION = 100000;

int H, W, Y;
vector<vector<int>> A(MAX_H, vector<int>(MAX_W));
vector<vector<bool>> visited(MAX_H, vector<bool>(MAX_W, false));

void simulate_flooding(int sea_level) {
    queue<pair<int, int>> q;
    // Initialize the queue with all the edges of the island at or below the current sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] <= sea_level) {
                q.push({i, j});
            }
        }
    }
    
    // Perform BFS-like traversal to simulate the flooding
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        visited[x][y] = true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Initially, the entire island is above sea level (sea_level = 0)
    int current_sea_level = 0;
    long long remaining_area = H * W;
    while (current_sea_level <= MAX_ELEVATION) {
        simulate_flooding(current_sea_level);
        long long sinking_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    if (A[i][j] <= current_sea_level) {
                        sinking_area++;
                        for (int k = 0; k < 4; ++k) {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }
        remaining_area -= sinking_area;
        cout << remaining_area << endl;
        current_sea_level++;
    }
    return 0;
}