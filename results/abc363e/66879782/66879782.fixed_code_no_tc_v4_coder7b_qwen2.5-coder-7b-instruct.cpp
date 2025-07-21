#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    vector<int> result(y + 1, 0);

    for (int year = 1; year <= y; ++year) {
        // Initialize the queue with all land cells that can be reached by the current sea level
        queue<pair<int, int>> q;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && height[i][j] > year) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Perform BFS to mark all connected land cells
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + di[i][0];
                int nc = c + di[i][1];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc] && height[nr][nc] > year) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        // Calculate the area of the island remaining above the sea level
        result[year] = h * w - count_if(all(visited), [](bool b) { return b; });
    }

    // Output the results
    for (int i = 1; i <= y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}