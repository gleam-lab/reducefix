#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W-1], make_pair(i, W-1));
    }
    for (int j = 1; j < W-1; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H-1][j], make_pair(H-1, j));
    }

    int ans = H * W;
    while (!pq.empty() && Y--) {
        auto [height, pos] = pq.top();
        pq.pop();

        if (visited[pos.first][pos.second]) continue;
        visited[pos.first][pos.second] = true;
        --ans;

        // Check all four directions
        static const array<pair<int, int>, 4> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto& [dx, dy] : dirs) {
            int nx = pos.first + dx, ny = pos.second + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                pq.emplace(max(height, A[nx][ny]), make_pair(nx, ny));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}