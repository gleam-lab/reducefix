#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

vector<ll> adj[MAXN];
ll dist[MAXN];
bool vis[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // BFS from node 1
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = true;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (ll v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }

            // Check if we found a cycle back to 1
            if (v == 1 && u != 1) {
                cout << dist[u] + 1;
                return 0;
            }
        }
    }

    // If no cycle found
    cout << "-1";
    return 0;
}