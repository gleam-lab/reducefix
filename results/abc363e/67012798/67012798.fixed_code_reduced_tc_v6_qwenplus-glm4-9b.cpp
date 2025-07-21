#include <bits/stdc++.h>

using namespace std;

#define dx 4
#define dy 4

int h, w, y;
int map[h][w];
bool visited[h][w];
int area[h][w];

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int dir_x[dy] = {-1, 1, 0, 0};
    int dir_y[dx] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < dx; i++) {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    // Count the area of the island that remains above sea level
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            area[i][j] = map[i][j] - 1;
        }
    }

    for (int i = 1; i <= y; i++) {
        int remaining_area = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (area[i][j] > i && !visited[i][j]) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}