#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1100
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] =  {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int MOD = 1e9 + 7;

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    queue<pair<int, int>> q;

    // Initialize the boundary cells
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int res = h * w;

    for(int level = 1; level <= y; level++) {
        int count = q.size();
        while(count--) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && grid[nx][ny] <= level) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        res -= q.size();
        cout << res << endl;
    }

    return 0;
}