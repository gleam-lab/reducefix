#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<ll>> graph;
map<ll, bool> seen;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll n, ll dist) {
    seen[n] = true;

    for (auto neighbor : graph[n]) {
        if (neighbor == 1) {
            ans = min(ans, dist + 1);
            continue;
        }

        if (!seen[neighbor]) {
            dfs(neighbor, dist + 1);
        }
    }

    seen[n] = false; // Backtrack to allow other paths
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }

    seen[1] = true; // Mark starting node as visited before DFS
    for (auto neighbor : graph[1]) {
        if (!seen[neighbor]) {
            dfs(neighbor, 1);
        }
    }

    if (ans != inf)
        cout << ans << endl;
    else
        cout << "-1" << endl;
}