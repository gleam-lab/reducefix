#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const int N = 1010;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    vector<vector<int>> sea_level(h, vector<int>(w, 0));

    rep(i, h) rep(j, w){
        if(grid[i][j] <= y){
            sea_level[i][j] = 1;
        }
    }

    queue<pair<int, int>> q;
    rep(i, h){
        if(sea_level[i][0] == 0) {
            q.push({i, 0});
            sea_level[i][0] = 1;
        }
        if(sea_level[i][w-1] == 0) {
            q.push({i, w-1});
            sea_level[i][w-1] = 1;
        }
    }
    rep(j, w){
        if(sea_level[0][j] == 0) {
            q.push({0, j});
            sea_level[0][j] = 1;
        }
        if(sea_level[h-1][j] == 0) {
            q.push({h-1, j});
            sea_level[h-1][j] = 1;
        }
    }

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        rep(k, 4){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && sea_level[nx][ny] == 0 && grid[nx][ny] <= y){
                sea_level[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    int remaining_area = 0;
    rep(i, h) rep(j, w){
        if(sea_level[i][j] == 0){
            remaining_area++;
        }
    }

    cout << remaining_area << endl;

    return 0;
}