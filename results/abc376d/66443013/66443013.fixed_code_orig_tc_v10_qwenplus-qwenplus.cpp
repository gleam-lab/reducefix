#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> visited;

ll ans = -1;
bool found = false;

// DFS to find the shortest cycle starting from node 1
void dfs(ll node, ll depth, ll parent) {
    visited[node] = true;

    for (auto neighbor : graph[node]) {
        if (!found && neighbor != parent) {
            if (neighbor == 1) {
                ans = depth + 1;
                found = true;
                return;
            }
            if (!visited[neighbor]) {
                dfs(neighbor, depth + 1, node);
            }
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
        if (visited.count(a) == 0) visited[a] = false;
        if (visited.count(b) == 0) visited[b] = false;
    }

    // Run DFS from node 1
    dfs(1, 1, -1);

    cout << (found ? ans : -1) << endl;
}