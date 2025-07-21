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

const ll MAX = 4 * 100000 + 5;
bool grid[MAX][MAX];
vector<ll> row_cnt(MAX), col_cnt(MAX);

int main() {
    ll h, w, q; cin >> h >> w >> q;
    rep(i, h) rep(j, w) grid[i][j] = true, row_cnt[i]++, col_cnt[j]++;

    while (q--) {
        ll r, c; cin >> r >> c;
        r--, c--;

        if (grid[r][c]) {
            grid[r][c] = false;
            row_cnt[r]--;
            col_cnt[c]--;
        } else {
            for (int dr = -1; dr <= 1; dr += 2) {
                for (int dc = -1; dc <= 1; dc += 2) {
                    if (dr == dc || dr == -dc) continue;
                    ll nr = r, nc = c;
                    while (nr >= 0 && nr < h && nc >= 0 && nc < w && !grid[nr][nc]) {
                        nr += dr;
                        nc += dc;
                    }
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                        grid[nr][nc] = false;
                        row_cnt[nr]--;
                        col_cnt[nc]--;
                    }
                }
            }
        }
    }

    ll ans = 0;
    rep(i, h) ans += row_cnt[i];
    rep(j, w) ans += col_cnt[j];

    cout << ans / 2 << endl;
    return 0;
}