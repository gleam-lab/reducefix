#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> island(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W, false));
    
    // Read the elevation data
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> island[i][j];
        }
    }
    
    // Priority queue to process sections based on their elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        pq.push({island[i][0], {i, 0}}); // Bottom edge
        pq.push({island[i][W - 1], {i, W - 1}}); // Top edge
        used[i][0] = used[i][W - 1] = true;
    }
    
    for (int j = 0; j < W; ++j) {
        pq.push({island[0][j], {0, j}}); // Left edge
        pq.push({island[H - 1][j], {H - 1, j}}); // Right edge
        used[0][j] = used[H - 1][j] = true;
    }
    
    // Total area of the island
    int total_area = H * W;
    
    // Process the sections that will sink each year
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto top = pq.top();
            pq.pop();
            
            // Update the area if this section sinks
            total_area -= used[top.second.first][top.second.second];
            
            // Spread the sea level to adjacent sections
            int dy[4] = {0, 1, 0, -1};
            int dx[4] = {1, 0, -1, 0};
            for (int d = 0; d < 4; ++d) {
                int ny = top.second.first + dy[d];
                int nx = top.second.second + dx[d];
                if (ny >= 0 && ny < H && nx >= 0 && nx < W && !used[ny][nx]) {
                    used[ny][nx] = true;
                    pq.push({island[ny][nx], {ny, nx}});
                }
            }
        }
        cout << total_area << endl;
    }
    
    return 0;
}