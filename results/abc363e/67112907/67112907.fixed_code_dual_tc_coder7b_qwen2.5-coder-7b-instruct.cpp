#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int h, x, y;
    bool operator<(const Cell &other) const {
        return h > other.h;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    priority_queue<Cell> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    
    // Initialize the priority queue with the boundary cells
    for(int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W-1], i, W-1);
    }
    for(int j = 0; j < W; ++j) {
        pq.emplace(A[0][j], 0, j);
        pq.emplace(A[H-1][j], H-1, j);
    }
    
    int ans = H * W;
    while(Y--) {
        while(!pq.empty()) {
            auto [h, x, y] = pq.top();
            if(h <= Y) break;
            pq.pop();
            --ans;
            for(int k = 0; k < 4; ++k) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}