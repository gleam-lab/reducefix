#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Initialize the queue with positions that are already below or at the initial sea level
    queue<pair<int, int>> q;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(A[i][j] <= 0) {
                q.push({i, j});
            }
        }
    }
    
    // Process each year's rising sea level
    for(int year = 1; year <= Y; ++year) {
        int count = 0;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        
        // BFS to mark all cells that will be submerged in the current year
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if(r < 0 || r >= H || c < 0 || c >= W || visited[r][c]) continue;
            visited[r][c] = true;
            
            // Check all four directions
            for(int dr = -1; dr <= 1; ++dr) {
                for(int dc = -1; dc <= 1; ++dc) {
                    if(dr * dc == 0 && abs(dr + dc) == 1) { // Only consider orthogonal moves
                        int nr = r + dr, nc = c + dc;
                        if(nr < 0 || nr >= H || nc < 0 || nc >= W || visited[nr][nc] || A[nr][nc] > year) continue;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        // Count the number of cells still above water after the current year
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if(A[i][j] > year && !visited[i][j]) {
                    ++count;
                }
            }
        }
        
        cout << count << '\n';
    }
    
    return 0;
}