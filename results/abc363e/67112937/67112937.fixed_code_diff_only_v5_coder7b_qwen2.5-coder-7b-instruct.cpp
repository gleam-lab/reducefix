#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i = 0;i < n;i++)
#define form(i,n) for(int i = 1;i <= n;i++)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)x.size())
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

const int N = 1e3 + 7;
int h, w, y;
int a[N][N];

void bfs(int level) {
    queue<pair<int,int>> q;
    bool vis[N][N] = {};
    forn(i,h) forn(j,w) if(a[i][j] > level && !vis[i][j]) {
        q.push({i,j});
        vis[i][j] = true;
    }
    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        forn(k,4) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny] || a[nx][ny] <= level) continue;
            q.push({nx,ny});
            vis[nx][ny] = true;
        }
    }
    forn(i,h) forn(j,w) if(vis[i][j]) a[i][j] = -1;
}

int main() {
    cin >> h >> w >> y;
    forn(i,h) forn(j,w) cin >> a[i][j];
    forn(i,y) {
        bfs(i);
        cout << h*w - count_if(all(a), [](int x){return x == -1;}) << '\n';
    }
    return 0;
}