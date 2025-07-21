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
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    // Priority queue to hold cells to be processed, ordered by elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Add all border cells to the queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                vis[i][j] = true;
            }
        }
    }

    int remaining = H * W;

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty()) {
            auto [elev, x, y] = pq.top();
            if (elev > year)
                break;
            pq.pop();
            --remaining;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }
        cout << remaining << "\n";
    }

    return 0;
}