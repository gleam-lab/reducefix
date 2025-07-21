#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with border sections
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> res(Y + 1, remaining); // res[0] is initial state (all sections remain)

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > year) break;
            pq.pop();
            --remaining;

            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
        res[year] = remaining;
    }

    for (int year = 1; year <= Y; ++year) {
        cout << res[year] << "\n";
    }

    return 0;
}