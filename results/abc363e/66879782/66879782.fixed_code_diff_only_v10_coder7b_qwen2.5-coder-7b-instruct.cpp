#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> height[i][j];
    
    vector<int> remaining_area(y + 1, h * w);
    
    for (int year = 1; year <= y; ++year) {
        // Initialize the queue with all cells that will sink at this sea level
        queue<pair<int, int>> q;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (height[i][j] <= year) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        // Perform BFS to sink all connected components
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nr = r + di[k][0];
                int nc = c + di[k][1];
                
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc] && height[nr][nc] <= year) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        
        // Update the remaining area
        remaining_area[year] = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j])
                    ++remaining_area[year];
            }
        }
    }
    
    // Output the results
    for (int year = 1; year <= y; ++year) {
        cout << remaining_area[year] << '\n';
    }
    
    return 0;
}