#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> A[i][j];
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dx = {{1, 0, -1, 0}, {0, 1, 0, -1}};
    
    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], {i, 0});
        pq.emplace(A[i][W - 1], {i, W - 1});
        used[i][0] = used[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(A[0][j], {0, j});
        pq.emplace(A[H - 1][j], {H - 1, j});
        used[0][j] = used[H - 1][j] = true;
    }
    
    int remaining_area = H * W;
    while (Y--) {
        if (pq.empty()) {
            cout << 0 << endl;
            continue;
        }
        
        auto top = pq.top();
        pq.pop();
        int r = top.second.first;
        int c = top.second.second;
        int elevation = top.first;
        
        // Check all adjacent sections
        for (int k = 0; k < 4; ++k) {
            int nr = r + dx[0][k];
            int nc = c + dx[1][k];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W || used[nr][nc]) continue;
            
            if (A[nr][nc] <= elevation) {
                pq.emplace(A[nr][nc], {nr, nc});
                used[nr][nc] = true;
            }
        }
        
        remaining_area--;
    }
    
    cout << remaining_area << endl;
    return 0;
}