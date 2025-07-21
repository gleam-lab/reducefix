#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w));

    // Read the height matrix
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    // Directions for moving up, down, left, right
    const vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Function to perform BFS to sink sections
    auto sinkSections = [&](int sea_level) {
        queue<pair<int, int>> q;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && height[i][j] <= sea_level) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && height[nx][ny] <= sea_level) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    };

    // Function to calculate the remaining land area
    auto calculateRemainingArea = [&]() -> int {
        int count = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    };

    // Process each sea level
    vector<int> results;
    for (int i = 1; i <= y; ++i) {
        sinkSections(i);
        results.push_back(calculateRemainingArea());
    }

    // Print results
    for (int i = 0; i < y; ++i) {
        cout << results[i] << '\n';
    }

    return 0;
}