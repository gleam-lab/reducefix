#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> island(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> island[i][j];
        }
    }

    int total_area = H * W;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    queue<pair<int, int>> q;

    // Initialize the queue with all the areas that are at the boundary of the island or below sea level
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || island[i][j] < 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && island[nx][ny] < 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    // Calculate the remaining area of the island
    int remaining_area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the remaining area for each year
    for (int year = 1; year <= Y; year++) {
        cout << remaining_area << endl;
    }

    return 0;
}