#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y + 1, remaining); // result[0] is initial state
    
    int current_level = 1;
    while (current_level <= Y && !pq.empty()) {
        while (!pq.empty() && pq.top().first < current_level) {
            auto cell = pq.top();
            pq.pop();
            int i = cell.second.first;
            int j = cell.second.second;
            remaining--;
            
            // Check adjacent cells
            const int dx[] = {-1, 1, 0, 0};
            const int dy[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        result[current_level] = remaining;
        current_level++;
    }
    
    // Fill remaining levels if Y is larger than the max elevation
    for (int i = current_level; i <= Y; ++i) {
        result[i] = remaining;
    }
    
    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << '\n';
    }
    
    return 0;
}