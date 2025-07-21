#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W)), vis(H, vector<int>(W));
    
    // Read input matrix A
    for(int i = 0; i < H; ++i)
        for(int j = 0; j < W; ++j) 
            cin >> A[i][j];

    // Initialize priority queue with boundary cells
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for(int i = 0; i < H; ++i){
        if(i == 0 || i == H-1){
            for(int j = 0; j < W; ++j) 
                if(!vis[i][j]){
                    pq.emplace(A[i][j], make_pair(i, j));
                    vis[i][j] = 1;
                }
        } else {
            pq.emplace(A[i][0], make_pair(i, 0)); vis[i][0] = 1;
            pq.emplace(A[i][W-1], make_pair(i, W-1)); vis[i][W-1] = 1;
        }
    }

    // Process each sea level rise
    while(Y--){
        int h = pq.top().first;
        if(h > Y+1) break; // If the highest cell in pq is higher than current sea level, stop processing
        pq.pop();

        int x = pq.top().second.first, y = pq.top().second.second;
        int cnt = 0;

        // Flood fill to mark all connected cells that can be submerged
        function<void(int,int)> dfs = [&](int i, int j){
            if(i < 0 || i >= H || j < 0 || j >= W || vis[i][j] || A[i][j] <= Y) return;
            vis[i][j] = 1;
            ++cnt;
            dfs(i-1, j), dfs(i+1, j), dfs(i, j-1), dfs(i, j+1);
        };

        dfs(x, y);
        cout << H*W-cnt << '\n';
    }

    return 0;
}