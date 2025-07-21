#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_Y = 100000;
const int MAX_VAL = 100000;

int H, W, N;
vector<vector<int>> A(MAX_H, vector<int>(MAX_W));
vector<vector<bool>> visited(MAX_H, vector<bool>(MAX_W, false));
vector<vector<bool>> will_sink(MAX_H, vector<bool>(MAX_W, false));
queue<pair<int, int>> q;

void bfs(int year) {
    int current_level = year;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if (A[nx][ny] <= current_level && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> H >> W >> N;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize the queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        q.push({i, 0});
        q.push({i, W - 1});
    }
    for (int j = 0; j < W; ++j) {
        q.push({0, j});
        q.push({H - 1, j});
    }

    // Process each year
    for (int year = 0; year < N; ++year) {
        bfs(year);
        // Calculate the remaining area
        long long remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}