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

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define el '\n'

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Priority queue to simulate flooding: smallest elevation first
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    vvi visited(H, vi(W, 0));

    // Initialize the border cells as they are adjacent to the sea
    rep(i, H) {
        pq.push({A[i][0], i * W + 0});
        pq.push({A[i][W-1], i * W + (W-1)});
        visited[i][0] = 1;
        visited[i][W-1] = 1;
    }
    rep3(j, 1, W-1) {
        pq.push({A[0][j], 0 * W + j});
        pq.push({A[H-1][j], (H-1) * W + j});
        visited[0][j] = 1;
        visited[H-1][j] = 1;
    }

    int remaining = H * W;
    vi result;

    // Directions for adjacent moves (up, right, down, left)
    vi dx = {-1, 0, 1, 0};
    vi dy = {0, 1, 0, -1};

    // Simulate year by year
    rep3(year, 1, Y + 1) {
        // Flood all cells with elevation <= current sea level (year)
        while (!pq.empty() && pq.top().first <= year) {
            auto [elevation, pos] = pq.top();
            pq.pop();

            int x = pos / W;
            int y = pos % W;

            // This cell is now underwater
            --remaining;

            // Check neighbors
            rep(d, 4) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({A[nx][ny], nx * W + ny});
                }
            }
        }
        result.push_back(remaining);
    }

    // Output each year's result
    for (int res : result) {
        cout << res << el;
    }
}