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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Initialize the grid and priority queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            pq.push({height[i][j], {i, j}});
        }
    }

    // Process each sea level
    for (int level = 1; level <= y; ++level) {
        vector<pair<int, int>> toSink;
        
        // Process all cells with height less than or equal to the current sea level
        while (!pq.empty() && pq.top().first <= level) {
            auto [H, p] = pq.top();
            pq.pop();
            if (visited[p.first][p.second]) continue;
            visited[p.first][p.second] = true;
            
            for (int k = 0; k < 4; ++k) {
                int nr = p.first + di[k][0];
                int nc = p.second + di[k][1];
                if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                if (height[nr][nc] <= level) {
                    toSink.push_back({nr, nc});
                }
            }
        }
        
        // Sink the identified cells
        for (auto& cell : toSink) {
            height[cell.first][cell.second] = level;
        }
    }

    // Calculate and output the remaining area for each sea level
    for (int level = 1; level <= y; ++level) {
        int count = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (height[i][j] > level) {
                    count++;
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}