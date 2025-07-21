#include <bits/stdc++.h>
using namespace std;

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

    auto comp = [&](int i, int j, int k, int l) {
        return A[i][j] > A[k][l];
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> pq(comp);
    
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Add boundary cells to the priority queue
    for (int i = 0; i < H; ++i) {
        if (!vis[i][0]) pq.emplace(A[i][0], make_pair(i, 0));
        if (!vis[i][W-1]) pq.emplace(A[i][W-1], make_pair(i, W-1));
    }
    for (int j = 0; j < W; ++j) {
        if (!vis[0][j]) pq.emplace(A[0][j], make_pair(0, j));
        if (!vis[H-1][j]) pq.emplace(A[H-1][j], make_pair(H-1, j));
    }

    int ans = H * W;
    while (Y--) {
        while (!pq.empty() && A[pq.top().second.first][pq.top().second.second] <= Y) {
            auto [h, pos] = pq.top();
            pq.pop();
            --ans;
            for (int k = 0; k < 4; ++k) {
                int dx = pos.first + d[k][0], dy = pos.second + d[k][1];
                if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy]) {
                    vis[dx][dy] = true;
                    pq.emplace(A[dx][dy], make_pair(dx, dy));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}