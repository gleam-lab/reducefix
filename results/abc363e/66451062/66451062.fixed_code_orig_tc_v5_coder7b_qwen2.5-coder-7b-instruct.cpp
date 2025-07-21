#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] =  {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int MOD = 1e9 + 7;
/*

*/
struct Node{
    int x,y,val;
    bool operator <(const Node &a) const{
        return val > a.val;
    }
};
signed main() {
    close;
    int h,w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h,vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    priority_queue<Node> q;
    for(int i = 0; i < h; i++) {
        q.push({i,0,grid[i][0]});
        q.push({i,w-1,grid[i][w-1]});
        vis[i][0] = vis[i][w-1] = true;
    }
    for(int i = 1; i < w - 1; i++) {
        q.push({0,i,grid[0][i]});
        q.push({h-1,i,grid[h-1][i]});
        vis[0][i] = vis[h-1][i] = true;
    }
    int res = h * w;
    int level = 1;

    for(int level = 1; level <= y; level++){
        while(!q.empty() and q.top().val <= level){
            Node cur = q.top();q.pop();
            res--;
            for(int i = 0; i < 4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx >= 0 and nx < h and ny >= 0 and ny < w and !vis[nx][ny] and grid[nx][ny] <= level){
                    vis[nx][ny] = true;
                    q.push({nx,ny,grid[nx][ny]});
                }
            }
        }
        cout << res << endl;
    }
    
    return 0;
}