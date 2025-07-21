#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 0) {
                pq.push({grid[i][j], {i, j}});
            }
        }
    }
    
    long long remaining_area = H * W;
    vector<long long> results(Y);
    
    for (int year = 0; year < Y; ++year) {
        while (!pq.empty()) {
            int h = pq.top().first;
            auto pos = pq.top().second;
            pq.pop();
            
            if (h > year + 1) continue;  // Skip if the height is greater than current sea level
            
            remaining_area -= 1;  // The current cell is now under water
            
            for (int dir = 0; dir < 4; ++dir) {
                int ni = pos.first + dx[dir];
                int nj = pos.second + dy[dir];
                
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (grid[ni][nj] <= h + 1) {
                    pq.push({grid[ni][nj], {ni, nj}});
                    grid[ni][nj] = h + 1;
                }
            }
        }
        results[year] = remaining_area;
    }
    
    for (int year = 0; year < Y; ++year) {
        cout << results[year] << endl;
    }
    
    return 0;
}