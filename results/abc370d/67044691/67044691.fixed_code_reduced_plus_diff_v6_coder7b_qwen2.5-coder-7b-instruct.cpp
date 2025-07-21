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

const ll INF = (1LL << 61);

struct Query {
    ll r, c;
};

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    vector<Query> queries(q);
    rep(i, q) {
        cin >> queries[i].r >> queries[i].c;
        queries[i].r--, queries[i].c--;
    }

    rep(i, q) {
        auto [r, c] = queries[i];
        if (!grid[r][c]) continue;

        grid[r][c] = false;
        // Check left
        for (ll j = c - 1; j >= 0; --j) {
            if (!grid[r][j]) break;
            grid[r][j] = false;
        }
        // Check right
        for (ll j = c + 1; j < w; ++j) {
            if (!grid[r][j]) break;
            grid[r][j] = false;
        }
        // Check up
        for (ll i = r - 1; i >= 0; --i) {
            if (!grid[i][c]) break;
            grid[i][c] = false;
        }
        // Check down
        for (ll i = r + 1; i < h; ++i) {
            if (!grid[i][c]) break;
            grid[i][c] = false;
        }
    }

    ll ans = 0;
    rep(i, h) rep(j, w) if (grid[i][j]) ++ans;
    
    cout << ans << '\n';
    return 0;
}