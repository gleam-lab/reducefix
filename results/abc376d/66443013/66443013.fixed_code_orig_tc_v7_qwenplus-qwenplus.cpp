#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> visited;
const ll INF = 1LL << 60;
ll ans = INF;

void dfs(ll node, ll depth, ll parent) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        if (neighbor == 1 && parent != -1) {
            // Found a cycle back to start with at least one edge
            ans = min(ans, depth + 1);
        } else if (!visited[neighbor]) {
            dfs(neighbor, depth + 1, node);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (graph.find(a) == graph.end()) visited[a] = false;
        if (graph.find(b) == graph.end()) visited[b] = false;
    }

    // Perform DFS from node 1 with initial depth 0 and no parent
    dfs(1, 0, -1);

    if (ans != INF)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}