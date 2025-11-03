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

    // We'll use a priority queue to simulate the flooding process
    // Smaller elevation gets processed first
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
    vvi visited(H, vi(W, false));

    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i * W + 0});
        pq.push({A[i][W-1], i * W + (W-1)});
        visited[i][0] = true;
        visited[i][W-1] = true;
    }
    rep3(j, 1, W-1) {
        pq.push({A[0][j], 0 * W + j});
        pq.push({A[H-1][j], (H-1) * W + j});
        visited[0][j] = true;
        visited[H-1][j] = true;
    }

    int remaining = H * W;
    vi result(Y + 1);

    // Directions for adjacent cells (up, right, down, left)
    vi dx = { -1, 0, 1, 0 };
    vi dy = { 0, 1, 0, -1 };

    // Process each year from 1 to Y
    for (int year = 1; year <= Y; ++year) {
        // Flood all cells with elevation <= current sea level (year)
        while (!pq.empty() && pq.top().first <= year) {
            auto [elevation, pos] = pq.top();
            pq.pop();
            
            int x = pos / W;
            int y = pos % W;
            
            // This cell is now underwater
            remaining--;
            
            // Check neighbors
            rep(d, 4) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({A[nx][ny], nx * W + ny});
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