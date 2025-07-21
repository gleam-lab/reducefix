#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> vis;
vector<vector<vector<pair<int, int>>>> events(100005); // Events per elevation

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    vis.resize(H, vector<bool>(W, false));

    int total_area = H * W;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Queue for BFS processing at each elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Initialize the border cells as starting points
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int ans = total_area;

    // BFS with elevation thresholds
    while (!pq.empty()) {
        auto [elev, x, y] = pq.top();
        pq.pop();

        // Already processed
        if (!vis[x][y]) {
            vis[x][y] = true;
            ans--;
        }

        // Propagate to neighbors
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= elev) {
                vis[nx][ny] = true;
                ans--;
                pq.emplace(elev, nx, ny);
            }
        }
    }

    // Track output over years
    vector<int> res(Y + 2, ans);

    // Maintain a pointer to track how many have sunk by year
    for (int y = 1; y <= Y; ++y) {
        cout << res[y] << "\n";
    }

    return 0;
}