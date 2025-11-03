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
    for (auto& row : A) {
        for (int& x : row) {
            cin >> x;
        }
    }

    // We'll simulate the flooding in reverse: instead of rising sea level,
    // we consider which cells get submerged at each year.
    // Use a min-heap to process cells in order of elevation.
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    vvi visited(H, vi(W, 0));

    // Add all border cells to the priority queue
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
    vector<int> ans(Y + 1, remaining); // ans[i] = area after i years

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    while (!pq.empty()) {
        auto [elev, pos] = pq.top();
        pq.pop();

        int r = pos / W, c = pos % W;

        // This cell gets flooded when sea level reaches 'elev'
        if (elev <= Y) {
            ans[elev]--;
        }

        // Propagate to unvisited neighbors
        rep(d, 4) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr < 0 || nc < 0 || nr >= H || nc >= W || visited[nr][nc]) continue;
            visited[nr][nc] = 1;
            pq.push({A[nr][nc], nr * W + nc});
        }
    }

    // Accumulate the submersion: ans[i] should be the remaining area after year i
    // But note: if a cell is submerged at year t, it remains submerged in later years.
    // So we need to propagate the decreases forward.
    for (int i = 1; i <= Y; i++) {
        ans[i] = min(ans[i], ans[i-1]); // area can't increase
    }

    // Output results for each year from 1 to Y
    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << el;
    }
}