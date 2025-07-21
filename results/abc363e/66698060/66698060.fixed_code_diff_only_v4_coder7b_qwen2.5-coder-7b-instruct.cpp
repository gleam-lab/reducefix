#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

int main(){
    ll h,w,y;cin >> h >> w >> y;
    vector<vector<ll>> room(h, vector<ll>(w));
    rep(i,h) rep(j,w) cin >> room[i][j];

    vector<vector<bool>> seen(h, vector<bool>(w, false));

    auto bfs = [&](ll level) {
        queue<pair<ll, ll>> q;
        rep(i, h) rep(j, w) {
            if (room[i][j] > level) {
                q.push({i, j});
                seen[i][j] = true;
            }
        }

        ll count = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            count++;

            rep(k, 4) {
                ll nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !seen[nx][ny] && room[nx][ny] > level) {
                    q.push({nx, ny});
                    seen[nx][ny] = true;
                }
            }
        }

        return count;
    };

    rep(i, y) {
        cout << bfs(i + 1) << '\n';
    }

    return 0;
}