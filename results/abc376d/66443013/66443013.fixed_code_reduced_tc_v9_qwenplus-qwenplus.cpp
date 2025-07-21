#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> seen;
map<ll, ll> dist;

void bfs(ll start) {
    queue<ll> q;
    q.push(start);
    dist[start] = 0;
    seen[start] = true;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        for (auto v : graph[u]) {
            if (!seen[v]) {
                seen[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }

    // We want to find the shortest path from node 1 back to itself
    // Do BFS from node 1 and find the shortest cycle
    bfs(1);

    // Find the minimum distance from any neighbor of 1 back to 1
    ll ans = numeric_limits<ll>::max();
    for (auto neighbor : graph[1]) {
        if (dist.find(neighbor) != dist.end()) {
            ans = min(ans, dist[neighbor] + 1); // +1 because we're counting the edge from 1 to neighbor
        }
    }

    if (ans != numeric_limits<ll>::max())
        cout << ans << endl;
    else
        cout << "-1" << endl;
}