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
#define pb push_back
#define el '\n'

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // We'll use a priority queue to simulate the rising sea level
    // Elements are {elevation, row, col}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vvi visited(H, vi(W, 0));

    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W-1], i, W-1});
            visited[i][W-1] = 1;
        }
    }
    rep3(j, 1, W-1) {
        pq.push({A[0][j], 0, j});
        visited[0][j] = 1;
        if (H > 1) {
            pq.push({A[H-1][j], H-1, j});
            visited[H-1][j] = 1;
        }
    }

    int remaining = H * W;
    vi result(Y + 1, 0);

    // Directions for adjacent cells (up, right, down, left)
    vi dx = { -1, 0, 1, 0 };
    vi dy = { 0, 1, 0, -1 };

    // Process each year from 1 to Y
    for (int year = 1; year <= Y; year++) {
        // Remove all cells with elevation <= current sea level (year)
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, r, c] = pq.top();
            pq.pop();
            remaining--;

            // Check neighbors
            rep(d, 4) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({A[nr][nc], nr, nc});
                }
            }
        }
        result[year] = remaining;
    }

    // Output results for each year
    rep3(i, 1, Y + 1) {
        cout << result[i] << el;
    }
}