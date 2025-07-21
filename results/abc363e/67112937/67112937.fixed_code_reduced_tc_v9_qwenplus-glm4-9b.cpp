#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> island(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    int startYear = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> island[i][j];
            if (!visited[i][j] && island[i][j] > startYear) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                                if (island[nx][ny] > startYear) {
                                    q.push({nx, ny});
                                    visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // Now visited contains the cells that are above the rising sea level in each year
    int remainingArea = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j]) {
                remainingArea++;
            }
        }
    }
    
    // Output the area of the island that remains above sea level for each year
    for (int year = 0; year < Y; ++year) {
        cout << remainingArea << "\n";
    }
    
    return 0;
}