#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

const int MAXN = 1000 + 5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int h, w, y; cin >> h >> w >> y;
    vl rooms(h * w);
    rep(i, h * w) cin >> rooms[i];

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    rep(i, h * w) {
        pq.push({rooms[i], i});
    }

    ll ans = h * w;
    rep(i, y) {
        auto [height, idx] = pq.top();
        pq.pop();
        --ans;

        int x = idx / w, y = idx % w;
        bool used[MAXN][MAXN]{};
        queue<int> q{{idx}};
        used[x][y] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int cx = cur / w, cy = cur % w;
            rep(d, 4) {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !used[nx][ny]) {
                    used[nx][ny] = true;
                    q.push(nx * w + ny);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}