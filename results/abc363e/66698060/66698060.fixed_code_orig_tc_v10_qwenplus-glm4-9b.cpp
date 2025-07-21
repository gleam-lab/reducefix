#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> heights(H, vector<int>(W));
    
    // Input the heights of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> heights[i][j];
        }
    }
    
    // Priority queue to store the indices of cells along with their heights
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize the priority queue with the grid's boundary cells
    for (int i = 0; i < H; ++i) {
        pq.push({heights[i][0], {i, 0}});
        pq.push({heights[i][W - 1], {i, W - 1}});
        if (i > 0) pq.push({heights[i - 1][i], {i - 1, i}});
        if (i < H - 1) pq.push({heights[i + 1][i], {i + 1, i}});
    }
    
    int remainingArea = H * W; // Initial area of the island
    cout << remainingArea << endl; // Output the area above sea level after 0 years
    
    for (int year = 1; year <= Y; ++year) {
        int removed = 0;
        while (!pq.empty() && pq.top().first <= year) {
            auto [height, pos] = pq.top();
            pq.pop();
            removed++;
            remainingArea--;
            
            // Check and add adjacent cells that will also sink
            for (int k = 0; k < 4; ++k) {
                int nextI = pos.first + dx[k];
                int nextJ = pos.second + dy[k];
                if (nextI >= 0 && nextI < H && nextJ >= 0 && nextJ < W && heights[nextI][nextJ] <= year) {
                    pq.push({heights[nextI][nextJ], {nextI, nextJ}});
                    heights[nextI][nextJ] = -1; // Mark as already checked
                }
            }
        }
        cout << remainingArea << endl;
    }
    
    return 0;
}