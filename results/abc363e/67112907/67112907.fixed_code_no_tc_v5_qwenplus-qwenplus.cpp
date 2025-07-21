#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, Y;
    std::cin >> H >> W >> Y;

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            std::cin >> A[i][j];
        }
    }

    // Priority queue to process cells in increasing order of elevation
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    std::vector<int> year_damage(Y + 2, 0);  // damage[i] = number of cells sunk in year i
    int remaining = H * W;

    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        if (height > Y) continue;

        // Count this cell's contribution to its year
        year_damage[height]++;
        
        for (auto& dir : d) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({A[nx][ny], nx, ny});
            }
        }
    }

    // For each year, accumulate the damage and output remaining area
    int total_damaged = 0;
    for (int year = 1; year <= Y; ++year) {
        total_damaged += year_damage[year];
        cout << (remaining - total_damaged) << "\n";
    }

    return 0;
}