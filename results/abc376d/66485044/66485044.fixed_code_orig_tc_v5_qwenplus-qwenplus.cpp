#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

vector<ll> vec[MAXN];
queue<ll> q;
ll dist[MAXN][2]; // dist[node][0] for even steps, dist[node][1] for odd steps
bool vis[MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        vec[u].push_back(v);
    }

    // Initialize distances to infinity
    for (ll i = 1; i <= n; ++i) {
        dist[i][0] = dist[i][1] = INF;
    }

    // Start BFS from node 1 with 0 steps (even step count)
    q.push(1);
    dist[1][0] = 0;
    vis[1][0] = true;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : vec[u]) {
            for (ll parity = 0; parity < 2; ++parity) {
                if (dist[u][parity] + 1 < dist[v][1 - parity]) {
                    dist[v][1 - parity] = dist[u][parity] + 1;
                    if (!vis[v][1 - parity]) {
                        q.push(v);
                        vis[v][1 - parity] = true;
                    }
                }
            }
        }
    }

    // The shortest cycle back to 1 with an odd number of edges
    if (dist[1][1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[1][1] << endl;
    }

    return 0;
}