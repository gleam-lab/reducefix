#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    
    while(q--) {
        ll r, c; cin >> r >> c;
        --r, --c;
        
        if(grid[r][c]) {
            grid[r][c] = false;
            continue;
        }
        
        queue<pair<int, int>> todo;
        todo.push({r, c});
        
        while(!todo.empty()) {
            auto [x, y] = todo.front(); todo.pop();
            
            if(x > 0 && grid[x - 1][y]) {
                grid[x - 1][y] = false;
                todo.push({x - 1, y});
            }
            if(x < h - 1 && grid[x + 1][y]) {
                grid[x + 1][y] = false;
                todo.push({x + 1, y});
            }
            if(y > 0 && grid[x][y - 1]) {
                grid[x][y - 1] = false;
                todo.push({x, y - 1});
            }
            if(y < w - 1 && grid[x][y + 1]) {
                grid[x][y + 1] = false;
                todo.push({x, y + 1});
            }
        }
    }
    
    ll ans = 0;
    for(auto &row: grid) ans += count(row.begin(), row.end(), true);
    cout << ans << endl;
}