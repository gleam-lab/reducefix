#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> island(H, vector<int>(W));
    queue<pair<int, int>> q;
    int totalArea = 0;

    // Read the island elevation and initialize the queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> island[i][j];
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                q.push({i, j});
                totalArea++;
            }
        }
    }

    // Process the queue
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + (dir == 0 ? 1 : (dir == 1 ? -1 : 0));
            int ny = y + (dir == 2 ? 1 : (dir == 3 ? -1 : 0));

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && island[nx][ny] <= island[x][y] + 1) {
                island[nx][ny] = island[x][y] + 1;
                q.push({nx, ny});
                totalArea++;
            }
        }
    }

    // Output the remaining area for each year
    for (int year = 0; year < Y; ++year) {
        cout << totalArea << endl;
    }

    return 0;
}