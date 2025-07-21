#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> sink_time(H, vector<int>(W, INT_MAX));
    priority_queue<pair<int, pair<int,int>>, 
                   vector<pair<int, pair<int,int>>>,
                   greater<pair<int, pair<int,int>>>> pq;
    
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    // Initialize boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                sink_time[i][j] = A[i][j];
                pq.push({A[i][j], {i, j}});
            }
        }
    }
    
    // Dijkstra-like algorithm to determine sink times for all cells
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int h = current.first;
        int x = current.second.first;
        int y = current.second.second;
        
        if (h > sink_time[x][y]) continue;
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            
            int new_sink_time = max(A[nx][ny], sink_time[x][y]);
            if (new_sink_time < sink_time[nx][ny]) {
                sink_time[nx][ny] = new_sink_time;
                pq.push({new_sink_time, {nx, ny}});
            }
        }
    }
    
    // Count the number of cells sinking at each year
    vector<int> cnt(Y + 2, 0); // cnt[y] = number of cells sinking at year y
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (sink_time[i][j] <= Y) {
                cnt[sink_time[i][j]]++;
            }
        }
    }
    
    // Compute prefix sum to get total sunk cells up to each year
    vector<int> prefix(Y + 1, 0);
    prefix[0] = cnt[0];
    for (int y = 1; y <= Y; ++y) {
        prefix[y] = prefix[y-1] + cnt[y];
    }
    
    // Output remaining area for each year
    for (int y = 1; y <= Y; ++y) {
        cout << H * W - prefix[y] << '\n';
    }
    
    return 0;
}