#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1005
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

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

    bool vis[MAXN][MAXN] = {false};
    priority_queue<Node> q;
    
    // Push border cells into the priority queue
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                q.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int res = h * w;
    vector<int> ans(Y + 1, res); // Initialize all answers to total area
    
    int current_level = 1;
    while(current_level <= Y && !q.empty()) {
        while(!q.empty() && q.top().val <= current_level) {
            Node cur = q.top(); q.pop();
            res--;
            for(int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[current_level] = res;
        current_level++;
    }
    
    // Fill remaining levels (if any) with the last computed res
    for(int i = current_level; i <= Y; i++) {
        ans[i] = res;
    }
    
    for(int i = 1; i <= Y; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}