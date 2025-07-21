#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    int A[MAX][MAX];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // We'll perform a multi-source BFS from all outer cells
    // Each cell will store the minimum sea level at which it sinks
    int sink_level[MAX][MAX];
    bool visited[MAX][MAX];
    memset(visited, 0, sizeof(visited));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // Initialize border cells with their own height as the sink level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                sink_level[i][j] = A[i][j];
                pq.push({A[i][j], {i, j}});
                visited[i][j] = true;
            } else {
                sink_level[i][j] = INT_MAX;
            }
        }
    }

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // BFS to compute sink levels
    while (!pq.empty()) {
        auto [sea_level, pos] = pq.top();
        auto [x, y] = pos;
        pq.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                // The sink level of neighbor is max(current cell's value, min neighbor height)
                int new_sink_level = max(sea_level, A[nx][ny]);
                if (new_sink_level < sink_level[nx][ny]) {
                    sink_level[nx][ny] = new_sink_level;
                    pq.push({new_sink_level, {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    // Count how many cells sink at each year
    vector<int> sink_count(Y + 2, 0); // index 0 unused, years are 1-based
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (sink_level[i][j] <= Y) {
                sink_count[sink_level[i][j]]++;
            }
        }
    }

    // Prefix sum to get total number of sunk cells up to each year
    vector<int> total_sunk(Y + 2, 0);
    for (int i = 1; i <= Y; ++i) {
        total_sunk[i] = total_sunk[i - 1] + sink_count[i];
        cout << (ll)H * W - total_sunk[i] << "\n";
    }

    return 0;
}