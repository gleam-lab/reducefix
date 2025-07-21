#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val; // Min-heap based on val
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Node> pq;

    // Initialize the priority queue with the border cells
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) {
            pq.push({i, 0, grid[i][0]});
            visited[i][0] = true;
        }
        if (!visited[i][W-1]) {
            pq.push({i, W-1, grid[i][W-1]});
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!visited[0][j]) {
            pq.push({0, j, grid[0][j]});
            visited[0][j] = true;
        }
        if (!visited[H-1][j]) {
            pq.push({H-1, j, grid[H-1][j]});
            visited[H-1][j] = true;
        }
    }

    int remaining = H * W;
    vector<int> result(Y + 1, 0); // result[i] is the answer for year i
    int current_level = 1;

    // Process each year from 1 to Y
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            Node node = pq.top();
            pq.pop();
            remaining--;
            // Check adjacent cells
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            for (int k = 0; k < 4; ++k) {
                int nx = node.x + dx[k];
                int ny = node.y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        result[year] = remaining;
    }

    // Output the results for each year from 1 to Y
    for (int year = 1; year <= Y; ++year) {
        cout << result[year] << '\n';
    }

    return 0;
}