#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
const int MAX = 1000;

void flood_fill(vector<vector<int>>& visited, const vector<vector<int>>& elevation, int x, int y, int currentSeaLevel) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && !visited[nx][ny] && elevation[nx][ny] > currentSeaLevel) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> elevation(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> elevation[i][j];
        }
    }
    
    vector<vector<int>> visited(h, vector<int>(w, 0));
    int remaining_area = 0;
    
    // Find initial land above sea level
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (elevation[i][j] > y && !visited[i][j]) {
                flood_fill(visited, elevation, i, j, y);
                remaining_area++;
            }
        }
    }
    
    // Output the result for each year
    for (int year = 1; year <= y; ++year) {
        cout << remaining_area << endl;
    }
    
    return 0;
}