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

    // Push boundary cells into the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
            }
        }
    }

    int current_area = H * W;
    vector<int> result(Y + 1);
    result[0] = current_area;

    for (int year = 1; year <= Y; year++) {
        while (!pq.empty() && pq.top().first <= year) {
            auto cell = pq.top();
            pq.pop();
            int x = cell.second.first;
            int y = cell.second.second;

            if (sunk[x][y]) continue;
            sunk[x][y] = true;
            current_area--;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    if (A[nx][ny] <= year) {
                        pq.push({A[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        result[year] = current_area;
    }

    for (int i = 1; i <= Y; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}