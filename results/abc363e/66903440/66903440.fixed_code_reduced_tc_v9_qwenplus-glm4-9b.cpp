#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W, Y;

int main() {
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    
    // Directions for moving in the grid (right, down, left, up)
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    deque<pair<int, int>> dq; // Queue for BFS
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<bool>> flooding(H, vector<bool>(W, false));
    
    // Initialize the BFS with cells on the borders
    for (int i = 0; i < H; i++) {
        flooding[i][0] = flooding[i][W-1] = true; // Left and right borders
        flooding[i][W-1] = flooding[i][W-1] = true;
    }
    for (int j = 0; j < W; j++) {
        flooding[0][j] = flooding[H-1][j] = true; // Top and bottom borders
        flooding[H-1][j] = flooding[H-1][j] = true;
    }
    
    // Get the first year of flooding
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (flooding[i][j]) {
                dq.push_back({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    ll previousArea = (ll)H * W; // Initial area of the island
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= A[x][y] + 1) {
                visited[nx][ny] = true;
                flooding[nx][ny] = true;
                dq.push_back({nx, ny});
            }
        }
    }
    
    // Calculate the remaining area after each year's flooding
    for (int y = 1; y <= Y; y++) {
        ll currentArea = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!flooding[i][j] && !visited[i][j]) {
                    currentArea++;
                }
                visited[i][j] |= flooding[i][j]; // Mark as visited
            }
        }
        cout << currentArea << endl;
        flooding = visited; // Prepare for next year
    }
    
    return 0;
}