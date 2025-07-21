#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define rep(i,n) for(int i=0;i<(int)n;i++)
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

const ll INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll h, w, q; cin >> h >> w >> q;
    vector<vector<ll>> grid(h, vector<ll>(w, 1));
    vector<ll> row_cnt(h, w), col_cnt(w, h);

    while(q--){
        ll r, c; cin >> r >> c;
        r--; c--;

        if(grid[r][c] == 1){
            grid[r][c] = 0;
            row_cnt[r]--;
            col_cnt[c]--;
        }else{
            bool flag = true;
            for(ll i = r - 1; i >= 0 && flag; i--){
                if(grid[i][c]){
                    grid[i][c] = 0;
                    row_cnt[i]--;
                    col_cnt[c]--;
                    flag = false;
                }
            }
            flag = true;
            for(ll i = r + 1; i < h && flag; i++){
                if(grid[i][c]){
                    grid[i][c] = 0;
                    row_cnt[i]--;
                    col_cnt[c]--;
                    flag = false;
                }
            }
            flag = true;
            for(ll j = c - 1; j >= 0 && flag; j--){
                if(grid[r][j]){
                    grid[r][j] = 0;
                    row_cnt[r]--;
                    col_cnt[j]--;
                    flag = false;
                }
            }
            flag = true;
            for(ll j = c + 1; j < w && flag; j++){
                if(grid[r][j]){
                    grid[r][j] = 0;
                    row_cnt[r]--;
                    col_cnt[j]--;
                    flag = false;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, h){
        rep(j, w){
            ans += grid[i][j];
        }
    }
    cout << ans << '\n';
    
    return 0;
}