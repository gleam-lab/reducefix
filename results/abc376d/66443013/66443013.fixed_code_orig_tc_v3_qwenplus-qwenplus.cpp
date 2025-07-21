#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> visited;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll node, ll depth) {
    if (visited[node]) return;
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        if (neighbor == 1) {
            ans = min(ans, depth + 1);
        } else if (!visited[neighbor]) {
            dfs(neighbor, depth + 1);
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
        if (!visited.count(a)) visited[a] = false;
        if (!visited.count(b)) visited[b] = false;
    }

    dfs(1, 0);

    if (ans != inf)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}