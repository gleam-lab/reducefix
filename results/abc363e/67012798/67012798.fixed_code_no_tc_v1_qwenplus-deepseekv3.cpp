#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize with border cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                submerged[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y + 1, 0);
    int current_level = 1;

    while (!pq.empty() && current_level <= Y) {
        auto top = pq.top();
        int level = top.first;
        int x = top.second.first;
        int y = top.second.second;

        if (level > current_level) {
            res[current_level] = ans;
            current_level++;
            if (current_level > Y) break;
            continue;
        }

        pq.pop();
        ans--;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !submerged[nx][ny]) {
                submerged[nx][ny] = true;
                pq.push({A[nx][ny], {nx, ny}});
            }
        }
    }

    // Fill remaining levels if sea level exceeds max elevation
    while (current_level <= Y) {
        res[current_level] = ans;
        current_level++;
    }

    for (int i = 1; i <= Y; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}