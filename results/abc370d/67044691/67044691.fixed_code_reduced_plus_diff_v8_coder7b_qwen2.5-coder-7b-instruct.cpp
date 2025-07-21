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

const ll INF = (1LL << 61);

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    while(q--) {
        ll r, c; cin >> r >> c;
        --r; --c;

        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            bool found = false;
            for(ll i = r - 1; i >= 0 && !found; --i) {
                if(grid[i][c]) {
                    grid[i][c] = false;
                    found = true;
                }
            }
            for(ll i = r + 1; i < h && !found; ++i) {
                if(grid[i][c]) {
                    grid[i][c] = false;
                    found = true;
                }
            }
            for(ll j = c - 1; j >= 0 && !found; --j) {
                if(grid[r][j]) {
                    grid[r][j] = false;
                    found = true;
                }
            }
            for(ll j = c + 1; j < w && !found; ++j) {
                if(grid[r][j]) {
                    grid[r][j] = false;
                    found = true;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, h) rep(j, w) if(grid[i][j]) ++ans;

    cout << ans << '\n';
    return 0;
}