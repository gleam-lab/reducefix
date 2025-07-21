#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Push all boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }
    
    int ans = H * W;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for (int i = 1; i <= Y; ++i) {
        while (!pq.empty() && pq.top().first <= i) {
            auto current = pq.top();
            pq.pop();
            ans--;
            
            for (int d = 0; d < 4; ++d) {
                int ny = current.second.first + dy[d];
                int nx = current.second.second + dx[d];
                
                if (ny >= 0 && ny < H && nx >= 0 && nx < W && !sunk[ny][nx]) {
                    sunk[ny][nx] = true;
                    pq.push({A[ny][nx], {ny, nx}});
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}