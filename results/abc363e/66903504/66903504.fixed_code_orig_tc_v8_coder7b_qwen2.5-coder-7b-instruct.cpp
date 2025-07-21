#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
const ll INF=1e18;

vector<ll> di={1,-1,0,0}, dj={0,0,1,-1};

void bfs(vector<vector<ll>>& h, vector<vector<bool>>& vis, queue<pair<ll,ll>>& q, ll sea_level) {
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for(ll k=0;k<4;k++) {
            ll ii=i+di[k], jj=j+dj[k];
            if(ii<0 || ii>=h.size() || jj<0 || jj>=h[0].size() || vis[ii][jj] || h[ii][jj]<=sea_level) continue;
            vis[ii][jj]=true;
            q.push({ii, jj});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll H, W, Y; cin >> H >> W >> Y;
    vector<vector<ll>> h(H, vector<ll>(W));
    for(auto &r:h) for(auto &c:r) cin >> c;

    vector<ll> ans(Y);
    for(ll y=0;y<Y;y++) {
        vector<vector<bool>> vis(H, vector<bool>(W, false));
        queue<pair<ll,ll>> q;
        for(ll i=0;i<H;i++) for(ll j=0;j<W;j++) 
            if(h[i][j]>y && (!i || !j || i==H-1 || j==W-1)) {
                vis[i][j]=true;
                q.push({i, j});
            }
        bfs(h, vis, q, y);
        for(ll i=0;i<H;i++) for(ll j=0;j<W;j++) 
            if(!vis[i][j]) ans[y]++;
    }

    for(auto a:ans) cout << a << '\n';

    return 0;
}