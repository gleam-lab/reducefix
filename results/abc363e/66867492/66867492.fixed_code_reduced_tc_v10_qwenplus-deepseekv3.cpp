#include <bits/stdc++.h>
using namespace std;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Push border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], {i, 0}});
        visited[i][0] = true;
        if (W > 1) {
            pq.push({A[i][W-1], {i, W-1}});
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.push({A[0][j], {0, j}});
        visited[0][j] = true;
        if (H > 1) {
            pq.push({A[H-1][j], {H-1, j}});
            visited[H-1][j] = true;
        }
    }

    int ans = H * W;
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int x = current.second.first;
            int y = current.second.second;
            --ans;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}