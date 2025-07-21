#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> visited;

const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll node, ll depth) {
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        if (neighbor == 1) {
            ans = min(ans, depth + 1);
            continue;
        }
        if (!visited[neighbor]) {
            dfs(neighbor, depth + 1);
        }
    }

    visited[node] = false; // Allow revisiting nodes through different paths
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

    if (ans != inf)
        cout << ans << endl;
    else
        cout << "-1" << endl;

    return 0;
}