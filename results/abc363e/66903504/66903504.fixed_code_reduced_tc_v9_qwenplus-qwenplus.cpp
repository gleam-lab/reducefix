#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Total area of the island
    ll total_area = H * 1LL * W;

    // Initialize visited matrix
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Prepare events: for each height y, store coordinates of cells whose value is y
    vector<vector<pair<int, int>>> events(Y + 2); // up to Y+1 to handle edge cases

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int val = A[i][j];
            if (val <= Y) {
                events[val].push_back({i, j});
            }
        }
    }

    // BFS queue
    queue<pair<int, int>> q;

    // Directions for BFS (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Function to check if cell is on border or adjacent to sea
    auto isBoundary = [&](int x, int y) {
        return (x == 0 || x == H - 1 || y == 0 || y == W - 1);
    };

    // For each year from 1 to Y
    for (int year = 1; year <= Y; ++year) {
        // Add all cells with elevation equal to current year that are on the boundary
        for (auto [x, y] : events[year]) {
            if (!visited[x][y] && isBoundary(x, y)) {
                visited[x][y] = true;
                q.push({x, y});
                total_area--;
            }
        }

        // Perform BFS to flood connected regions
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    if (A[nx][ny] <= year) {
                        visited[nx][ny] = true;
                        total_area--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Output remaining area above sea level
        cout << total_area << '\n';
    }
}