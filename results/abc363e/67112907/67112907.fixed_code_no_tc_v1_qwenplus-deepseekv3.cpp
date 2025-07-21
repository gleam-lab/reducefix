#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

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

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<int>> sink_time(H, vector<int>(W, -1));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                sink_time[i][j] = A[i][j];
            }
        }
    }

    while (!pq.empty()) {
        auto [time, x, y] = pq.top();
        pq.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && sink_time[nx][ny] == -1) {
                sink_time[nx][ny] = max(time, A[nx][ny]);
                pq.emplace(sink_time[nx][ny], nx, ny);
            }
        }
    }

    vector<int> count(Y + 2, 0);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (sink_time[i][j] <= Y) {
                count[sink_time[i][j]]++;
            } else {
                count[Y + 1]++;
            }
        }
    }

    int remaining = H * W;
    for (int i = 0; i < Y; ++i) {
        remaining -= count[i];
        cout << remaining << '\n';
    }

    return 0;
}