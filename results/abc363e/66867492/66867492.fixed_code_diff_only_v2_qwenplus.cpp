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
    vector<vector<bool>> used(H, vector<bool>(W, false));
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq; // min-heap: (elevation, index)

    // Add all border cells to the priority queue
    rep(i, H) {
        pq.emplace(A[i][0], i * W + 0);
        pq.emplace(A[i][W-1], i * W + (W-1));
        used[i][0] = true;
        used[i][W-1] = true;
    }
    rep3(j, 1, W-1) {
        pq.emplace(A[0][j], 0 * W + j);
        pq.emplace(A[H-1][j], (H-1) * W + j);
        used[0][j] = true;
        used[H-1][j] = true;
    }

    int remaining = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    vi results;

    // Process each year from 1 to Y
    rep3(year, 1, Y+1) {
        // Remove all cells with elevation <= current sea level (year)
        while (!pq.empty() && pq.top().first <= year) {
            auto [elev, idx] = pq.top();
            pq.pop();
            
            int x = idx / W, y = idx % W;
            // This cell is now submerged

            // Check neighbors
            rep(d, 4) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                if (!used[nx][ny]) {
                    used[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx * W + ny);
                }
            }
            remaining--;
        }
        cout << remaining << el;
    }
}