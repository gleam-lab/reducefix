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

#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
#define el '\n'
#define pb push_back

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Mark matrix to check if cell is submerged
    vvi used(H, vi(W, 0));

    // Min-heap priority queue to process cells in increasing elevation order
    pq_c pq;

    // Initialize the boundary (coastal) cells
    rep(i, H) {
        if (!used[i][0]) {
            used[i][0] = 1;
            pq.emplace(A[i][0], i * W + 0);
        }
        if (!used[i][W - 1]) {
            used[i][W - 1] = 1;
            pq.emplace(A[i][W - 1], i * W + (W - 1));
        }
    }

    rep(j, W) {
        if (!used[0][j]) {
            used[0][j] = 1;
            pq.emplace(A[0][j], 0 * W + j);
        }
        if (!used[H - 1][j]) {
            used[H - 1][j] = 1;
            pq.emplace(A[H - 1][j], (H - 1) * W + j);
        }
    }

    int totalCells = H * W;
    int remaining = totalCells;
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    // We'll store the result for each year
    vi results(Y + 2, 0); // index by year

    // Process all events in order of rising sea level
    while (!pq.empty()) {
        int elev;
        int pos;
        tie(elev, pos) = pq.top();
        pq.pop();

        int r = pos / W;
        int c = pos % W;

        // If this elevation is <= current year (sea level), it's submerged
        // So we simulate this for all years up to Y
        if (elev > Y) continue;

        remaining--;
        results[elev] = remaining;

        // Try to expand to neighbors
        rep(d, 4) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !used[nr][nc]) {
                used[nr][nc] = 1;
                pq.emplace(A[nr][nc], nr * W + nc);
            }
        }
    }

    // Fill in any missing values (carry forward the last known value)
    int last = remaining;
    rep3(i, 1, Y + 1) {
        if (results[i] == 0) {
            results[i] = last;
        } else {
            last = results[i];
        }
    }

    // Output results for each year
    rep3(i, 1, Y + 1) {
        cout << results[i] << el;
    }

    return 0;
}