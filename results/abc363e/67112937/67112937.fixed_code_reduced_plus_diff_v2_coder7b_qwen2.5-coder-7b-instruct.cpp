#include <bits/stdc++.h>
using namespace std;

#define vi(x) vector<x>
#define vvi(x) vector<vector<x>>
#define vvvi(x) vector<vector<vector<x>>>
#define all(v) v.begin(), v.end()
#define sz(a) ((long long)(a.size()))
#define pb push_back
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpii vector<pii>
#define mp make_pair
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define repr(i, a, b) for(ll i = b-1; i >= a; --i)

const int MAXN = 1e3+10;
vii(int) A(MAXN), vis(MAXN, vi(bool)(MAXN));

bool ok(int h){
    queue<pll> q;
    rep(i, 0, sz(A)){
        if(A[i] <= h && !vis[i][0]){
            q.push({i, 0});
            vis[i][0] = true;
        }
    }
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        rep(dir, 0, 4){
            int nx = x + d[dir][0], ny = y + d[dir][1];
            
            if(nx < 0 || nx >= sz(A) || ny < 0 || ny >= sz(A[nx])) continue;
            if(vis[nx][ny] || A[nx][ny] > h) continue;
            
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    return sz(A)-count(all(vis), false);
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    rep(i, 0, n) rep(j, 0, m) cin >> A[i][j];
    
    vll ans(k);
    rep(i, 0, k){
        int h; cin >> h;
        ans[i] = ok(h);
    }
    
    rep(i, 0, k) cout << ans[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}