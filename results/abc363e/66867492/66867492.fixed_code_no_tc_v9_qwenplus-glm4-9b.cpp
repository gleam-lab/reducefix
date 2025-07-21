#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));
    vector<vector<int>> dx = {{1, 0, -1, 0}, {0, 1, 0, -1}};
    queue<pair<int, pair<int, int>>> q; // (elevation, {row, col})
    
    // Read the elevation matrix A and initialize the queue and used matrix
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            used[i][j] = A[i][j] == 0; // Water cells are initially used
            if (!used[i][j]) { // If it's not water
                q.push({A[i][j], {i, j}});
            }
        }
    }

    // Process the queue and simulate the sinking process
    while (!q.empty()) {
        auto [elevation, pos] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; ++dir) {
            int ni = pos.first + dx[0][dir];
            int nj = pos.second + dx[1][dir];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            
            if (A[ni][nj] > elevation) { // If the adjacent cell is higher than the current
                A[ni][nj]--;
                if (A[ni][nj] > 0) { // If the cell does not sink completely
                    q.push({A[ni][nj], {ni, nj}});
                }
                used[ni][nj]++;
            }
        }
    }

    // Calculate the remaining area above sea level for each year
    for (int i = 0; i < Y; ++i) {
        int remaining_area = 0;
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                remaining_area += !used[x][y]; // Cells that have not sunk
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}