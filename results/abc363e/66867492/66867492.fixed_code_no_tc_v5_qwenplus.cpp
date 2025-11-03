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

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Mark cells that are initially connected to the sea (border cells)
    vvi used(H, vi(W, 0));
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq; // min-heap: {elevation, index}
    
    auto add_to_pq = [&](int i, int j) {
        if (!used[i][j]) {
            used[i][j] = 1;
            pq.push({A[i][j], i * W + j});
        }
    };

    // Add all border cells
    for (int i = 0; i < H; ++i) {
        add_to_pq(i, 0);
        add_to_pq(i, W - 1);
    }
    for (int j = 1; j < W - 1; ++j) {
        add_to_pq(0, j);
        add_to_pq(H - 1, j);
    }

    int remaining = H * W;
    vi result(Y + 1); // Store result for each year

    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    // Process sinking in increasing order of elevation
    while (!pq.empty()) {
        auto [elev, idx] = pq.top();
        pq.pop();
        
        int x = idx / W;
        int y = idx % W;

        // This cell sinks at year = elev (if elev <= Y)
        if (elev <= Y) {
            // All years from current elevation onwards lose this cell
            for (int yr = elev; yr <= Y; ++yr) {
                result[yr]--;
            }
        }

        // Propagate to neighbors
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !used[nx][ny]) {
                add_to_pq(nx, ny);
            }
        }
    }

    // Compute cumulative area for each year
    for (int i = 1; i <= Y; ++i) {
        remaining += result[i]; // Apply the change
        cout << remaining << '\n';
    }
}