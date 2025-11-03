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
        for (auto& x : row) {
            cin >> x;
        }
    }

    // Priority queue to process cells in increasing order of elevation
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    vvi used(H, vi(W, 0));

    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i * W + 0});
        pq.push({A[i][W-1], i * W + (W-1)});
        used[i][0] = 1;
        used[i][W-1] = 1;
    }
    rep3(j, 1, W-1) {
        pq.push({A[0][j], 0 * W + j});
        pq.push({A[H-1][j], (H-1) * W + j});
        used[0][j] = 1;
        used[H-1][j] = 1;
    }

    int remaining = H * W;
    vi result(Y + 1); // result[i] = area after i years
    result[0] = remaining;

    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    // Process each year
    rep3(year, 1, Y + 1) {
        // Remove all cells with elevation <= current sea level
        while (!pq.empty() && pq.top().first <= year) {
            auto [elev, pos] = pq.top();
            pq.pop();
            
            int r = pos / W;
            int c = pos % W;
            
            // This cell sinks
            if (result[year-1] > 0) {
                remaining--;
            }

            // Check neighbors
            rep(d, 4) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && !used[nr][nc]) {
                    used[nr][nc] = 1;
                    pq.push({A[nr][nc], nr * W + nc});
                }
            }
        }
        result[year] = remaining;
        cout << result[year] << el;
    }
}