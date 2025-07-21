#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        pq.push({grid[i][0], {i, 0}});
        visited[i][0] = true;
        pq.push({grid[i][w-1], {i, w-1}});
        visited[i][w-1] = true;
    }

    for (int j = 1; j < w-1; ++j) {
        pq.push({grid[0][j], {0, j}});
        visited[0][j] = true;
        pq.push({grid[h-1][j], {h-1, j}});
        visited[h-1][j] = true;
    }

    int total_area = h * w;
    int current_time = 0;

    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();

        if (height > current_time) break;

        int i = pos.first, j = pos.second;
        if (visited[i][j]) continue;

        visited[i][j] = true;
        --total_area;

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj]) {
                pq.push({grid[ni][nj], {ni, nj}});
            }
        }
    }

    for (int t = 1; t <= y; ++t) {
        while (!pq.empty() && pq.top().first == t) {
            pq.pop();
        }
        cout << total_area << endl;
    }

    return 0;
}