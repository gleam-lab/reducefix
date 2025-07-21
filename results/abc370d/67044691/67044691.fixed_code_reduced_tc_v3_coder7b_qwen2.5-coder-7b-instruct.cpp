#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep(i,r) for(ll i=0;i<(ll)r;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const int INF = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll h,w,q;cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));
    
    while(q--){
        ll r,c;cin >> r >> c;
        --r, --c;
        
        if(grid[r][c] == 1){
            grid[r][c] = 0;
            continue;
        }
        
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({r, c});
        visited.insert({r, c});
        
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            
            int dx[] = {0, 0, -1, 1};
            int dy[] = {-1, 1, 0, 0};
            
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited.count({nx, ny}) && grid[nx][ny] == 1){
                    q.push({nx, ny});
                    visited.insert({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }
    }
    
    int count = 0;
    rep(i, h) rep(j, w) if(grid[i][j] == 1) count++;
    cout << count << endl;
    
    return 0;
}