#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Binary matrix to mark whether a cell is still above sea level
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // For each year, we will track how many cells are still above sea level

    // We'll use BFS from the sea, expanding as the sea level rises
    // To do this efficiently, we sort all cells by their height
    using Cell = tuple<int, int, int>; // height, x, y
    priority_queue<Cell, vector<Cell>, greater<>> pq;

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue with the boundary cells (adjacent to sea)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    vector<int> result(Y + 2); // result[year] = area
    int remaining = H * W;

    // We simulate up to Y years
    int current_year = 0;
    while (current_year < Y) {
        // Advance the sea level until it reaches current_year + 1
        while (!pq.empty() && get<0>(pq.top()) <= current_year + 1) {
            auto [h, x, y] = pq.top();
            pq.pop();

            if (!alive[x][y]) continue;
            alive[x][y] = false;
            --remaining;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }

        ++current_year;
        result[current_year] = remaining;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}