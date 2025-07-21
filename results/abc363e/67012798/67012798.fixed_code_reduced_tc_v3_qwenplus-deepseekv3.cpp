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

    // Push border cells into the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], {i, j}});
            }
        }
    }

    int ans = H * W;
    vector<int> results(Y + 1, ans); // results[0] is initial state

    int current_level = 1;
    while (current_level <= Y && !pq.empty()) {
        while (!pq.empty() && pq.top().first < current_level) {
            auto [val, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;

            if (sunk[x][y]) continue;
            sunk[x][y] = true;
            ans--;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    if (A[nx][ny] <= val) {
                        pq.push({A[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        results[current_level] = ans;
        current_level++;
    }

    for (int i = 1; i <= Y; i++) {
        cout << results[i] << '\n';
    }

    return 0;
}