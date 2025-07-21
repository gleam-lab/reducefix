#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, val;
    bool operator<(const Node& other) const {
        return val > other.val; // Min-heap based on val
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<Node> pq;
    
    // Push border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!sunk[i][0]) {
            pq.push({i, 0, grid[i][0]});
            sunk[i][0] = true;
        }
        if (!sunk[i][W-1]) {
            pq.push({i, W-1, grid[i][W-1]});
            sunk[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!sunk[0][j]) {
            pq.push({0, j, grid[0][j]});
            sunk[0][j] = true;
        }
        if (!sunk[H-1][j]) {
            pq.push({H-1, j, grid[H-1][j]});
            sunk[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y + 1, 0); // result[i] is the area at sea level i
    int current_level = 1;
    
    while (current_level <= Y) {
        while (!pq.empty() && pq.top().val <= current_level) {
            Node node = pq.top();
            pq.pop();
            remaining--;
            
            // Check adjacent cells
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            for (int k = 0; k < 4; ++k) {
                int nx = node.x + dx[k];
                int ny = node.y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny]) {
                    sunk[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        result[current_level] = remaining;
        current_level++;
    }
    
    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << '\n';
    }
    
    return 0;
}