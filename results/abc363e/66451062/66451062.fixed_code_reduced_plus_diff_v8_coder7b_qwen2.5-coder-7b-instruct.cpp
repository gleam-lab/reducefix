#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1100
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    for (int level = 1; level <= y; level++) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        // Collect all sections that will sink at the current sea level
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] <= level) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // Perform BFS to mark all connected sections that will sink
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= level) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        // Calculate the remaining area above the sea level
        int remaining_area = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << endl;
    }

    return 0;
}