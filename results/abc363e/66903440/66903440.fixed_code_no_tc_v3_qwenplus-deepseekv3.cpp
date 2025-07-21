#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    
    int ans = H * W;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    vector<queue<pair<int,int>>> queues(100002); // Max elevation is 1e5
    
    // Initialize border cells
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i == 0 || i == H-1 || j == 0 || j == W-1) {
                if(!sunk[i][j]) {
                    sunk[i][j] = true;
                    queues[A[i][j]].push({i, j});
                }
            }
        }
    }
    
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    
    for(int y = 1; y <= Y; y++) {
        // Process all queues <= y
        for(int level = 1; level <= y; level++) {
            while(!queues[level].empty()) {
                auto [i, j] = queues[level].front();
                queues[level].pop();
                if(A[i][j] > y) continue; // Shouldn't sink yet
                ans--;
                
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < H && nj >= 0 && nj < W) {
                        if(!sunk[ni][nj] && A[ni][nj] <= y) {
                            sunk[ni][nj] = true;
                            queues[A[ni][nj]].push({ni, nj});
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}