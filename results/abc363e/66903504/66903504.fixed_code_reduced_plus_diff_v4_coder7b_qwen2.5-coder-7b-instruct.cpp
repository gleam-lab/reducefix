#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> seen(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the boundary cells as already seen
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                seen[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // Directions for moving up, down, left, right
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        int remaining_area = H * W;
        
        // Process all cells that were newly submerged at the current sea level
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            
            // Decrease the remaining area since this cell is submerged
            --remaining_area;
            
            // Explore neighbors
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !seen[ni][nj] && A[ni][nj] <= sea_level) {
                    seen[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }

        // Output the remaining area
        cout << remaining_area << endl;
    }

    return 0;
}