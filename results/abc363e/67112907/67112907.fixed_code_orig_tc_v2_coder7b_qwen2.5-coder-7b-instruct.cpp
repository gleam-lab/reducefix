#include <bits/stdc++.h>
using namespace std;

struct Node {
    int h, x, y;
    bool operator<(const Node &other) const {
        return h > other.h;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W)), dist(H, vector<int>(W, INT_MAX));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Node> pq;
    
    // Read input matrix
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
            pq.push({A[i][j], i, j});
            dist[i][j] = A[i][j];
        }
    }
    
    // Directions array for moving up, down, left, right
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while(!pq.empty()) {
        auto [h, x, y] = pq.top(); pq.pop();
        
        if(h > Y) continue;
        
        for(auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            
            if(A[nx][ny] <= h && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = min(dist[nx][ny], h);
                pq.push({h, nx, ny});
            }
        }
    }
    
    for(int i = 0; i < Y; ++i) {
        cout << accumulate(accumulate(dist.begin(), dist.end()), [](int sum, const auto& v){return sum + count_if(v.begin(), v.end(), [&](int e){return e > i;});}) << '\n';
    }
    
    return 0;
}