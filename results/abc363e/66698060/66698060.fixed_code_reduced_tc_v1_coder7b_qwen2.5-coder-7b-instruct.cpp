#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define rep1(i, n) for (int i = 1; i <= (int)n; ++i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define trav(a, x) for(auto&a:a)
#define LLD long double
#define LL long long
#define int LL
#define sz(x) ((int)x.size())

const int INF = 1e9 + 7;
const int MXN = 1000;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void bfs(vector<vector<int>>& grid, int sr, int sc, int target, int& ans) {
    queue<pair<int, int>> q;
    q.emplace(sr, sc);
    grid[sr][sc] = target;
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if (nr >= 0 && nr < sz(grid) && nc >= 0 && nc < sz(grid[0]) && grid[nr][nc] == 1) {
                q.emplace(nr, nc);
                grid[nr][nc] = target;
                --ans;
            }
        }
    }
}

vector<int> solve(int h, int w, int y, vector<vector<int>>& grid) {
    vector<int> result(y);
    
    int total_land = 0;
    rep(i, h) rep(j, w) {
        if (grid[i][j] == 1) {
            ++total_land;
        }
    }
    
    result[0] = total_land;
    
    for (int t = 1; t <= y; ++t) {
        int target = t;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 1 && i > 0 && grid[i - 1][j] == target) {
                    bfs(grid, i, j, target, total_land);
                    break;
                }
                if (grid[i][j] == 1 && j > 0 && grid[i][j - 1] == target) {
                    bfs(grid, i, j, target, total_land);
                    break;
                }
            }
            if (total_land == 0) break;
        }
        result[t - 1] = total_land;
    }
    
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];
    
    vector<int> result = solve(h, w, y, grid);
    
    rep(i, y) cout << result[i] << '\n';
    
    return 0;
}