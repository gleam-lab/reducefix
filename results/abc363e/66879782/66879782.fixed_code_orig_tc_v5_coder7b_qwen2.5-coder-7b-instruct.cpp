#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> height(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pii> q;

    // Directions: up, down, left, right
    const int di[] = {-1, 1, 0, 0};
    const int dj[] = {0, 0, -1, 1};

    for (int year = 1; year <= y; ++year) {
        // Initialize the queue with cells that will sink in this year
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && height[i][j] <= year) {
                    q.push({height[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Process the queue to sink all connected cells
        while (!q.empty()) {
            auto [h, pos] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = pos.first + di[k];
                int nj = pos.second + dj[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && height[ni][nj] <= year) {
                    visited[ni][nj] = true;
                    q.push({height[ni][nj], {ni, nj}});
                }
            }
        }

        // Count the remaining area above water
        int remaining_area = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }

        // Reset the visited array for the next year
        fill(visited.begin(), visited.end(), vector<bool>(w, false));

        // Print the result for the current year
        cout << remaining_area << '\n';
    }

    return 0;
}