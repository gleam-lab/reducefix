#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W)), visited(H, vector<bool>(W));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    
    // Read input and initialize the queue and visited matrix
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if(A[i][j] <= Y) {
                q.emplace(A[i][j], make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    
    // Directions for moving up, down, left, right
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Process each sea level rise
    for(int y = 1; y <= Y; ++y) {
        while(!q.empty() && q.top().first <= y) {
            auto [h, pos] = q.top(); q.pop();
            auto [x, y] = pos;
            
            // Explore all four directions
            for(auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= y) {
                    q.emplace(A[nx][ny], make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        
        // Calculate remaining area
        int remaining_area = 0;
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if(!visited[i][j]) {
                    ++remaining_area;
                }
            }
        }
        cout << remaining_area << '\n';
    }
    
    return 0;
}