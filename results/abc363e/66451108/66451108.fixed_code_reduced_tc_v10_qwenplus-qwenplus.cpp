#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1010
#define dx(x) ({ int ddx[] = {0, 0, 1, -1}; ddx[x]; })
#define dy(y) ({ int ddy[] = {1, -1, 0, 0}; ddy[y]; })

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

const int MOD = 1e9 + 7;

signed main() {
    close;
    int h, w; cin >> h >> w;
    int Y; cin >> Y;
    int grid[MAXN][MAXN];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    bool vis[MAXN][MAXN] = {};
    priority_queue<Node> pq;

    // Initialize border cells
    for(int i = 0; i < h; i++) {
        if(!vis[i][0]) {
            vis[i][0] = true;
            pq.push({i, 0, grid[i][0]});
        }
        if(!vis[i][w-1]) {
            vis[i][w-1] = true;
            pq.push({i, w-1, grid[i][w-1]});
        }
    }
    for(int j = 1; j < w-1; j++) {
        if(!vis[0][j]) {
            vis[0][j] = true;
            pq.push({0, j, grid[0][j]});
        }
        if(!vis[h-1][j]) {
            vis[h-1][j] = true;
            pq.push({h-1, j, grid[h-1][j]});
        }
    }

    int total = h * w;
    vector<int> ans(Y+2, 0);

    // We'll track how many cells are removed at each level
    vector<int> removed_at(100010, 0);

    // Use BFS with priority queue to simulate rising sea level
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, v = cur.val;

        // This cell will be submerged when sea reaches v
        // So we count it as removed at this level
        if(v <= Y)
            removed_at[v]++;
        else
            removed_at[Y]++;  // For values beyond Y, they won't sink within the time frame

        for(int d = 0; d < 4; d++) {
            int nx = x + dx(d);
            int ny = y + dy(d);
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    // Compute cumulative removals
    int removed = 0;
    for(int i = 1; i <= Y; i++) {
        removed += removed_at[i];
        cout << (total - removed) << endl;
    }

    return 0;
}