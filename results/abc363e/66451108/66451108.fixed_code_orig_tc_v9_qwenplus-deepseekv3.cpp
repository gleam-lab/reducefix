#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int h, w, Y;
    cin >> h >> w >> Y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;
    
    // Push all border cells into the priority queue
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                q.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }
    
    int res = h * w;
    vector<int> ans(Y + 1, res);
    
    for (int level = 1; level <= Y; level++) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top();
            q.pop();
            res--;
            
            for (int k = 0; k < 4; k++) {
                int nx = cur.x + (k == 2) - (k == 3);
                int ny = cur.y + (k == 0) - (k == 1);
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[level] = res;
    }
    
    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}