#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void printRemainingArea(int h, int w, const vector<vector<int>>& area, intSeaLevel) {
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> q;

    // Add all cells with elevation < sea level to the queue
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (area[i][j] <= seaLevel) {
                q.push({i, j});
            }
        }
    }

    // Perform BFS to find all cells that will sink
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && area[nx][ny] <= seaLevel) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    // Calculate remaining area
    int remainingArea = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j]) {
                remainingArea++;
            }
        }
    }

    cout << remainingArea << endl;
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> elevation(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> elevation[i][j];
        }
    }

    for (int year = 1; year <= y; year++) {
        printRemainingArea(h, w, elevation, year);
        elevation[0].erase(0, 1); // Remove the row of the sea level
        elevation[h - 1].insert(elevation[h - 1].end(), 1, 0); // Add the new row at the bottom
        elevation.insert(elevation.begin(), vector<int>(w, 0)); // Add the new row at the top
        elevation[h - 1].insert(elevation[h - 1].end(), 1, 0); // Add the new row at the bottom
    }

    return 0;
}