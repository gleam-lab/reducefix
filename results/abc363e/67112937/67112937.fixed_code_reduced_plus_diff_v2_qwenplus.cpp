#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int H, W, Y;
    std::cin >> H >> W >> Y;

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
    std::vector<std::vector<bool>> vis(H, std::vector<bool>(W, false));
    
    // Add all border cells to the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int ans = H * W;
    std::vector<int> result(Y);

    for (int year = 0; year < Y; year++) {
        int sea_level = year + 1;
        
        // Process all cells that will sink at current sea level
        while (!pq.empty()) {
            auto [elevation, x, y] = pq.top();
            if (elevation > sea_level) break;
            
            pq.pop();
            ans--;
            
            // Check neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        
        result[year] = ans;
    }

    for (int i = 0; i < Y; i++) {
        std::cout << result[i] << "\n";
    }

    return 0;
}