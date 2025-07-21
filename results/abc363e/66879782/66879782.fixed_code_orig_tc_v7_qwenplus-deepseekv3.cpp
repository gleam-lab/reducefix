#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> sink_time(H, vector<int>(W, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    // Directions: up, down, left, right
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Initialize border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                sink_time[i][j] = A[i][j];
                pq.emplace(A[i][j], i, j);
            }
        }
    }
    
    // Dijkstra-like algorithm to compute sink times
    while (!pq.empty()) {
        auto [t, i, j] = pq.top();
        pq.pop();
        
        if (t > sink_time[i][j]) continue;
        
        for (auto [di, dj] : dirs) {
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            
            int new_t = max(t, A[ni][nj]);
            if (new_t < sink_time[ni][nj]) {
                sink_time[ni][nj] = new_t;
                pq.emplace(new_t, ni, nj);
            }
        }
    }
    
    // Count the number of cells sinking at each year
    vector<int> sink_count(Y + 2, 0);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (sink_time[i][j] <= Y) {
                sink_count[sink_time[i][j]]++;
            }
        }
    }
    
    // Compute prefix sum
    vector<int> prefix(Y + 1, 0);
    prefix[0] = sink_count[0];
    for (int y = 1; y <= Y; ++y) {
        prefix[y] = prefix[y-1] + sink_count[y];
    }
    
    // Output results
    for (int y = 1; y <= Y; ++y) {
        cout << H * W - prefix[y] << '\n';
    }
    
    return 0;
}