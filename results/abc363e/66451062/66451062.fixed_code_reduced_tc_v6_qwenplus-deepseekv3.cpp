#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int x, y, val;
    bool operator < (const Node &other) const {
        return val > other.val; // Min-heap based on val
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

    vector<vector<bool>> vis(H, vector<bool>(W, false));
    priority_queue<Node> pq;

    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int submerged = 0;
    int current_level = 1;
    vector<int> result(Y);

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            Node node = pq.top();
            pq.pop();
            submerged++;
            for (int k = 0; k < 4; ++k) {
                int nx = node.x + dx[k];
                int ny = node.y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        result[year - 1] = H * W - submerged;
    }

    for (int year = 0; year < Y; ++year) {
        cout << result[year] << '\n';
    }

    return 0;
}