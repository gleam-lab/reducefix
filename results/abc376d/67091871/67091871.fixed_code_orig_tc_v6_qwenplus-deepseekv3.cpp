#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
vector<int> adj[200005];
ll vis[200005];
ll dist[200005];

ll bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    dist[1] = 0;
    vis[1] = 1;
    ll mn = 200005;

    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        for (int v : adj[u]) {
            if (v == 1) {
                mn = min(mn, (ll)d + 1);
                continue;
            }
            if (vis[v] == 0) {
                vis[v] = 1;
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
    return mn == 200005 ? -1 : mn;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ll ans = bfs();
    cout << ans << endl;
    return 0;
}