#include <bits/stdc++.h>
using namespace std;

struct Point {
    int h, x, y;
    bool operator<(const Point& other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    priority_queue<Point> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // Initialize the priority queue with the boundary cells
    for(int i = 0; i < H; ++i) {
        if(!visited[i][0]) pq.push({A[i][0], i, 0});
        if(!visited[i][W-1]) pq.push({A[i][W-1], i, W-1});
    }
    for(int j = 0; j < W; ++j) {
        if(!visited[0][j]) pq.push({A[0][j], 0, j});
        if(!visited[H-1][j]) pq.push({A[H-1][j], H-1, j});
    }
    
    while(Y--) {
        int cnt = 0;
        while(!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if(h <= Y) break;
            visited[x][y] = true;
            ++cnt;
            for(auto& [dx, dy]: dirs) {
                int nx = x + dx, ny = y + dy;
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
                pq.push({A[nx][ny], nx, ny});
            }
        }
        cout << H*W-cnt << '\n';
    }
    
    return 0;
}