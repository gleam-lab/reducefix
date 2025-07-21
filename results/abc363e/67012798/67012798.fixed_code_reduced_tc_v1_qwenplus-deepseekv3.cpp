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

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> result(Y + 1, ans);

    int current_sea_level = 1;
    while (!pq.empty() && current_sea_level <= Y) {
        while (!pq.empty() && pq.top().first <= current_sea_level) {
            auto [elev, pos] = pq.top();
            pq.pop();
            ans--;

            for (int d = 0; d < 4; d++) {
                int nx = pos.first + dx[d];
                int ny = pos.second + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    sunk[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        result[current_sea_level] = ans;
        current_sea_level++;
    }

    for (int i = 1; i <= Y; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}