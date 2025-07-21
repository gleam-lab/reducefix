#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];

struct Cell {
    int h, x, y;
    bool operator<(const Cell &other) const {
        return h > other.h;
    }
};

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(int sea_level) {
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Cell> pq;
    
    // Initialize the priority queue with all cells that are above the initial sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > sea_level) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int count = 0;
    
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();
        
        if (h <= sea_level) continue;
        
        count++;
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                pq.push({A[nx][ny], nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    set<int> unique_levels;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            unique_levels.insert(A[i][j]);
        }
    }
    
    vector<int> levels(unique_levels.begin(), unique_levels.end());
    
    for (int i = 0; i < Y; ++i) {
        cout << bfs(levels[i]) << '\n';
    }
    
    return 0;
}