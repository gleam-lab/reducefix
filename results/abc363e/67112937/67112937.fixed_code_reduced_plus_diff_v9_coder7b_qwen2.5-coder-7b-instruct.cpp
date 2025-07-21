#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int INF = 1e9;

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

    vector<vector<bool>> vis(H, vector<bool>(W, false));

    for (int k = 1; k <= Y; ++k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        // Initialize the priority queue with boundary cells
        for (int i = 0; i < H; ++i) {
            if (!vis[i][0]) pq.emplace(A[i][0], make_pair(i, 0));
            if (!vis[i][W - 1]) pq.emplace(A[i][W - 1], make_pair(i, W - 1));
        }
        for (int j = 1; j < W - 1; ++j) {
            if (!vis[0][j]) pq.emplace(A[0][j], make_pair(0, j));
            if (!vis[H - 1][j]) pq.emplace(A[H - 1][j], make_pair(H - 1, j));
        }

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            
            if (h > k || vis[pos.first][pos.second]) continue;
            
            vis[pos.first][pos.second] = true;
            
            for (auto &dir : d) {
                int nx = pos.first + dir[0], ny = pos.second + dir[1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= k) {
                    pq.emplace(A[nx][ny], make_pair(nx, ny));
                }
            }
        }

        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j]) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}