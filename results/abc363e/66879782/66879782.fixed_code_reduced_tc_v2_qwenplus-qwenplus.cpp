#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    // Min-heap to process the outer boundary cells
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Initialize the queue with the boundary cells
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.emplace(height[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    // Directions: up, down, left, right
    const array<array<int, 2>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    // To store the earliest year when each cell sinks
    vector<int> sink_year(h * w + 1, 0); // index = year, value = area sunk at that year

    while (!pq.empty()) {
        auto [H, r, c] = pq.top();
        pq.pop();

        for (const auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc]) {
                visited[nr][nc] = true;
                int sink_time = min(H, height[nr][nc]);
                sink_year[sink_time]++;
                pq.emplace(max(H, height[nr][nc]), nr, nc);
            }
        }
    }

    // Cumulative sum of areas sinking each year
    vector<ll> prefix(y + 2, 0);
    for (int i = 1; i <= y; ++i) {
        prefix[i] = prefix[i - 1] + sink_year[i];
    }

    // Total land area and output
    ll total_area = static_cast<ll>(h) * w;
    for (int i = 1; i <= y; ++i) {
        cout << total_area - prefix[i] << "\n";
    }

    return 0;
}