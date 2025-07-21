#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }
    
    vector<int> land_area(y + 1, h * w);
    
    for (int level = 1; level <= y; ++level) {
        queue<pair<int, int>> q;
        
        // Identify new sections that will submerge at this level
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && height[i][j] <= level) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        // Perform flood fill to mark all connected submerged sections
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nr = r + di[k][0];
                int nc = c + di[k][1];
                
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc] && height[nr][nc] <= level) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        
        // Calculate the remaining land area
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    ++land_area[level];
                }
            }
        }
    }
    
    // Print the results
    for (int i = 1; i <= y; ++i) {
        cout << land_area[i] << '\n';
    }
    
    return 0;
}