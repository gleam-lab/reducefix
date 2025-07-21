#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> visited;

const ll INF = 1LL << 60;
ll ans = INF;

// Use a map to track depth during DFS
void dfs(ll node, ll depth) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        if (neighbor == 1) {
            ans = min(ans, depth + 1);
        } else {
            dfs(neighbor, depth + 1);
        }
    }

    visited[node] = false; // Allow revisiting nodes via different paths
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (!visited.count(a)) visited[a] = false;
        if (!visited.count(b)) visited[b] = false;
    }

    // Start DFS from node 1 with depth 0
    visited[1] = true;
    for (auto neighbor : graph[1]) {
        dfs(neighbor, 1);
    }

    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}