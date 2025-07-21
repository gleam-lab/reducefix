#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Section {
    int elevation, x, y;
    bool operator<(const Section& other) const {
        return elevation > other.elevation;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    priority_queue<Section> pq;
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            pq.push({grid[i][j], i, j});
        }
    }
    
    while (!pq.empty()) {
        int n = pq.size();
        
        for (int k = 0; k < n; ++k) {
            auto [elevation, x, y] = pq.top(); pq.pop();
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        
        if (--y == 0) break;
    }
    
    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) ++count;
        }
    }
    
    cout << count << '\n';
    
    return 0;
}