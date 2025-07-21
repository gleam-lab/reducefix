#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep2(i,m,n) for(int i=(m);i<(int)n;i++)
#define rep3(i,m,n,d) for(int i=(m);i<(int)n;i+=(d))
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
    int h,w,y;
    cin >> h >> w >> y;
    vector<vector<int>> room(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> room[i][j];

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    queue<pair<int,int>> q;
    rep(i,h) rep(j,w) {
        if(room[i][j] > y) {
            visited[i][j] = true;
            q.push({i,j});
        }
    }

    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};

    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();

        rep(i,4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && room[nx][ny] <= y) {
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w) if(visited[i][j]) ans++;

    cout << ans << endl;

    return 0;
}