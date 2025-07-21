#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Priority queue to store {elevation, row, col}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W));

    // Initialize the priority queue with boundary sections
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W-1], make_pair(i, W-1));
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H-1][j], make_pair(H-1, j));
    }

    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();

        if (vis[pos.first][pos.second]) continue;
        vis[pos.first][pos.second] = true;

        for (auto& dir : d) {
            int nx = pos.first + dir[0];
            int ny = pos.second + dir[1];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                pq.emplace(A[nx][ny], make_pair(nx, ny));
            }
        }
    }

    int total_area = H * W;
    vector<int> result(Y);

    for (int year = 0; year < Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto [height, pos] = pq.top();
            pq.pop();
            total_area--;
        }
        result[year] = total_area;
    }

    for (int i = 0; i < Y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}