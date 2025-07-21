#include <bits/stdc++.h>
using namespace std;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using Pi = pair<int, int>;
using pq_c = priority_queue<Pi, vector<Pi>, greater<Pi>>;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // visited matrix to mark cells connected to the sea
    vvi visited(H, vi(W, 0));

    // Priority queue to process cells in increasing order of elevation
    pq_c pq;

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i * W + j);
                visited[i][j] = 1;
            }
        }
    }

    // Total land area
    int remaining = H * W;

    // Directions: up, right, down, left
    vi dx = {-1, 0, 1, 0};
    vi dy = {0, 1, 0, -1};

    // Process queries
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            int val = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            int x = pos / W;
            int y = pos % W;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.emplace(A[nx][ny], nx * W + ny);
                }
            }
        }
        cout << remaining - (H * W - static_cast<int>(pq.size())) << '\n';
    }
}