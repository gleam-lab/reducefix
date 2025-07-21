#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = int64_t;

int H, W, Y;
const int MAX_ELEVATION = 200000 + 10;
vector<vector<int>> A;
vector<vector<bool>> visited;
int total_area;

// Directions: up, right, down, left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<queue<pair<int, int>>> sea_queue(MAX_ELEVATION);

bool in_bounds(int x, int y) {
    return (x >= 0 && x < H && y >= 0 && y < W);
}

void process_sea_level(int sea_level) {
    while (!sea_queue[sea_level].empty()) {
        auto [x, y] = sea_queue[sea_level].front();
        sea_queue[sea_level].pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (in_bounds(nx, ny) && !visited[nx][ny]) {
                if (A[nx][ny] <= sea_level) {
                    visited[nx][ny] = true;
                    total_area--;
                    // This cell will cause adjacent cells to be processed
                    sea_queue[max(sea_level, A[nx][ny])].push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    visited.resize(H, vector<bool>(W, false));

    total_area = H * W;

    // Initialize borders
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                total_area--;
                sea_queue[A[i][j]].push({i, j});
            }
        }
    }

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        process_sea_level(year);
        cout << total_area << "\n";
    }

    return 0;
}