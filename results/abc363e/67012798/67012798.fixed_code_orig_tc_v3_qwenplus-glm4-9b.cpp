#include <bits/stdc++.h>

using namespace std;

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

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(Y + 1);

    // Initialize the queue for each sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == 0) {
                q[0].push({i, j});
            }
            visited[i][j] = A[i][j] == 0;
        }
    }

    int initially_flooded = count(q[0].begin(), q[0].end(), pair<int, int>());
    int remaining_area = H * W - initially_flooded;

    for (int year = 1; year <= Y; ++year) {
        int num_flooded_this_year = 0;
        while (!q[year].empty()) {
            auto [x, y] = q[year].front();
            q[year].pop();

            // Check all four neighbors
            for (int dx : {-1, 0, 1}) {
                for (int dy : {-1, 0, 1}) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                        continue;
                    }

                    // If the neighbor has not been visited and is within the elevation range
                    if (!visited[nx][ny] && A[nx][ny] <= year) {
                        visited[nx][ny] = true;
                        num_flooded_this_year++;
                        q[year + 1].push({nx, ny});
                    }
                }
            }
        }

        // Subtract the number of cells that will flood this year from the remaining area
        remaining_area -= num_flooded_this_year;
        cout << remaining_area << '\n';
    }

    return 0;
}