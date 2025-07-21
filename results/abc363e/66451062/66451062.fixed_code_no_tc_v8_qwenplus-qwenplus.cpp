#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vi>
#define vvb vector<vector<bool>>
#define endl '\n'
#define fastio() ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

signed main() {
    fastio();
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    // Visited array to mark cells that have been submerged
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Priority queue to process cells in increasing order of elevation
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({grid[i][j], {i, j}});
                vis[i][j] = true;
            }
        }
    }

    // To store how many cells remain above water at each year
    vector<int> remaining(Y + 2, H * W); // Default is full island area

    // BFS with Dijkstra-like approach
    while (!pq.empty()) {
        auto [elevation, pos] = pq.top();
        auto [x, y] = pos;
        pq.pop();

        // The year when this cell gets submerged
        int submerge_year = elevation;

        if (submerge_year > Y)
            break;

        // Decrease the remaining area for this and all future years
        remaining[submerge_year]--;

        // Propagate to neighbors only if not yet visited
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({grid[nx][ny], {nx, ny}});
            }
        }
    }

    // Cumulative minimum to get final result for each year
    for (int i = 1; i <= Y; ++i) {
        remaining[i] = min(remaining[i], remaining[i - 1]);
        cout << remaining[i] << endl;
    }

    return 0;
}