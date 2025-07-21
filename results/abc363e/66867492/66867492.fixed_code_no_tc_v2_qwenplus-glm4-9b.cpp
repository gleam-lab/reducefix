#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W, false));

    cin >> &A[0][0];
    
    // Initialize the queue with edges of the grid and their elevations
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Fill the queue with initial cells that are on the edge and touching the sea
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], {i, 0});
        pq.emplace(A[i][W - 1], {i, W - 1});
        used[i][0] = used[i][W - 1] = true;
    }
    
    for (int j = 1; j < W - 1; ++j) {
        pq.emplace(A[0][j], {0, j});
        pq.emplace(A[H - 1][j], {H - 1, j});
        used[0][j] = used[H - 1][j] = true;
    }
    
    int ans = H * W; // Total initial area
    
    while (Y--) {
        // Process cells that are about to sink
        while (!pq.empty() && pq.top().first <= Y) {
            auto [elev, pos] = pq.top();
            pq.pop();
            int y = pos.first, x = pos.second;
            
            // Check adjacent cells that will also sink
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int ny = y + dy, nx = x + dx;
                    if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
                        if (A[ny][nx] <= Y && !used[ny][nx]) {
                            used[ny][nx] = true;
                            ans--;
                            pq.emplace(A[ny][nx], {ny, nx});
                        }
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}