#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                used[i][j] = true;
            }
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W - 1], make_pair(i, W - 1));
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H - 1][j], make_pair(H - 1, j));
    }

    int ans = H * W;
    const vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty() && pq.top().first <= y) {
            auto [height, pos] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = pos.first + dy[d], nx = pos.second + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || used[ny][nx]) continue;
                used[ny][nx] = true;
                pq.emplace(A[ny][nx], make_pair(ny, nx));
            }
        }
        cout << ans << endl;
    }
}