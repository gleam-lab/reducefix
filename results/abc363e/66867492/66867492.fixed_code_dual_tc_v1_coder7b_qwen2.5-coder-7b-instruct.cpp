#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Read the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], make_pair(i, j));
                used[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

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

    return 0;
}