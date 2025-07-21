#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int height[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Cell {
    int x, y, level;
};

// Directions: up, down, left, right
int di[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void bfs(vector<vector<bool>>& seen, vector<Cell>& queue, int targetLevel) {
    while (!queue.empty()) {
        Cell curr = queue.back();
        queue.pop_back();
        
        for (int d = 0; d < 4; ++d) {
            int nx = curr.x + di[d][0];
            int ny = curr.y + di[d][1];
            
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || seen[nx][ny] || height[nx][ny] > targetLevel) {
                continue;
            }
            
            seen[nx][ny] = true;
            queue.emplace_back(nx, ny, targetLevel);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    
    // Read the heights of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> height[i][j];
        }
    }

    // Initialize the queue with boundary cells
    vector<Cell> queue;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                queue.emplace_back(i, j, height[i][j]);
                visited[i][j] = true;
            }
        }
    }

    vector<int> result(Y + 1, 0);
    
    // Process each year
    for (int year = 1; year <= Y; ++year) {
        vector<vector<bool>> seen(H, vector<bool>(W, false));
        
        // Perform BFS to mark all cells above the current sea level
        bfs(seen, queue, year);
        
        // Count the number of cells remaining above the current sea level
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!seen[i][j] && height[i][j] > year) {
                    count++;
                }
            }
        }
        
        // Update the result for the current year
        result[year] = count;
    }
    
    // Print the results for each year
    for (int year = 1; year <= Y; ++year) {
        cout << result[year] << "\n";
    }

    return 0;
}