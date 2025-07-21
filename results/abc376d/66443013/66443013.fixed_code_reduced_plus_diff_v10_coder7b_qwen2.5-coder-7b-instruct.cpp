#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<ll, vector<ll>> graph;
map<ll, bool> seen;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll node, ll steps) {
    if (steps >= ans) return; // Prune if current path length is already worse than best found so far
    seen[node] = true;
    for (auto neighbor : graph[node]) {
        if (neighbor == 1) {
            ans = min(ans, steps + 1);
            continue;
        }
        if (!seen[neighbor]) {
            dfs(neighbor, steps + 1);
        }
    }
    seen[node] = false; // Backtrack
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Assuming undirected graph
    }

    dfs(1, 0); // Start DFS from node 1 with 0 steps

    if (ans != inf) cout << ans << endl;
    else cout << "-1" << endl;

    return 0;
}