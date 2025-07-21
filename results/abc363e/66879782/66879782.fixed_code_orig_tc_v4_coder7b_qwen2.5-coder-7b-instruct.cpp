#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

struct Cell {
    int x, y, elevation;
    bool operator<(const Cell& other) const {
        return elevation > other.elevation;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<int>> sink(h, vector<int>(w, INT_MAX));
    priority_queue<Cell> pq;
    int di[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    // Read the heights and initialize the priority queue
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> height[i][j];
            sink[i][j] = INT_MAX;
            if(i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink[i][j] = height[i][j];
                pq.push({i, j, height[i][j]});
            }
        }
    }
    
    // Process each cell in the priority queue
    while (!pq.empty()) {
        auto [r, c, H] = pq.top();
        pq.pop();
        if (visited[r][c]) continue;
        visited[r][c] = true;
        
        for (int k = 0; k < 4; ++k) {
            int nr = r + di[k][0];
            int nc = c + di[k][1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (height[nr][nc] <= H && sink[nr][nc] > H) {
                sink[nr][nc] = H;
                pq.push({nr, nc, H});
            }
        }
    }
    
    // Calculate the areas above each sea level
    vector<int> pref(y + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink[i][j] <= y) {
                pref[sink[i][j]]++;
            }
        }
    }
    
    for (int i = 1; i <= y; ++i) {
        pref[i] += pref[i - 1];
        cout << h * w - pref[i] << '\n';
    }
    
    return 0;
}