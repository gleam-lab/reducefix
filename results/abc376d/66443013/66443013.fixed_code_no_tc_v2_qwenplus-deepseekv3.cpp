#include<bits/stdc++.h>
using namespace std;
using ll=long long;

map<ll, vector<ll>> graph;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll current, ll start, ll depth, map<ll, bool>& visited) {
    visited[current] = true;
    for (auto neighbor : graph[current]) {
        if (neighbor == start && depth > 1) {
            ans = min(ans, depth + 1);
            continue;
        }
        if (!visited[neighbor]) {
            dfs(neighbor, start, depth + 1, visited);
        }
    }
    visited[current] = false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    map<ll, bool> visited;
    dfs(1, 1, 0, visited);

    if (ans != inf) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}