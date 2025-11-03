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

    // Priority queue to process cells in increasing order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vvi visited(H, vi(W, false));

    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = true;
        if (W > 1) {
            pq.push({A[i][W-1], i, W-1});
            visited[i][W-1] = true;
        }
    }
    rep3(j, 1, W-1) {
        pq.push({A[0][j], 0, j});
        visited[0][j] = true;
        if (H > 1) {
            pq.push({A[H-1][j], H-1, j});
            visited[H-1][j] = true;
        }
    }

    int remaining = H * W;
    vi result(Y + 1, 0);
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    // Process cells in order of increasing elevation
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();

        // For each year up to elev, this cell will be submerged
        for (int year = 1; year <= min(elev, Y); ++year) {
            if (result[year] == 0) {
                result[year] = remaining;
            }
        }
        remaining--;

        // Propagate to neighbors
        rep(d, 4) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                visited[ni][nj] = true;
                pq.push({A[ni][nj], ni, nj});
            }
        }
    }

    // Fill in any remaining years with the final area
    for (int year = 1; year <= Y; ++year) {
        if (result[year] == 0) {
            result[year] = remaining;
        }
        cout << result[year] << el;
    }
}