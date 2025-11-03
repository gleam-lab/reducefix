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

    std::vector A(H, std::vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    // Create a list of all cells with their elevation and coordinates
    std::vector<std::array<int, 3>> cells;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cells.push_back({A[i][j], i, j});
        }
    }
    
    // Sort by elevation in ascending order
    std::sort(cells.begin(), cells.end());

    std::vector vis(H, std::vector<char>(W, 0));
    int ans = H * W;
    
    // Process each year from 1 to Y
    auto it = cells.begin();
    for (int year = 1; year <= Y; year++) {
        // Add all cells with elevation <= current sea level (year)
        while (it != cells.end() && (*it)[0] <= year) {
            auto [h, x, y] = *it;
            if (!vis[x][y]) {
                vis[x][y] = 1;
                ans--;
                
                // Check if this cell is on the border or adjacent to sea
                // Actually, we need to simulate the flooding properly
                // Instead, we'll use BFS from all newly submerged border-adjacent cells
            }
            ++it;
        }
        
        // We need to simulate the actual flooding process:
        // Only cells connected to the sea (border) through <= sea_level path will sink
        // So we do a multi-source BFS from all border cells that are submerged
        
        // But note: our current approach doesn't correctly model connectivity to sea
        // Let's rework: maintain a queue of cells that are connected to sea
    }
    
    // Correct approach: start from borders and expand inward using priority queue
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<std::array<int, 3>>> pq;
    std::vector new_vis(H, std::vector<char>(W, 0));
    
    // Initialize with all border cells
    for (int j = 0; j < W; j++) {
        pq.push({A[0][j], 0, j});
        new_vis[0][j] = 1;
        pq.push({A[H-1][j], H-1, j});
        new_vis[H-1][j] = 1;
    }
    for (int i = 1; i < H-1; i++) {
        pq.push({A[i][0], i, 0});
        new_vis[i][0] = 1;
        pq.push({A[i][W-1], i, W-1});
        new_vis[i][W-1] = 1;
    }
    
    ans = H * W;
    std::vector<int> result;
    
    for (int year = 1; year <= Y; year++) {
        // Process all cells with height <= current sea level
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > year) break;
            pq.pop();
            
            // This cell is now underwater
            ans--;
            
            // Check neighbors
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + d[dir][0];
                int ny = y + d[dir][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !new_vis[nx][ny]) {
                    new_vis[nx][ny] = 1;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        result.push_back(ans);
    }
    
    for (int res : result) {
        std::cout << res << "\n";
    }

    return 0;
}