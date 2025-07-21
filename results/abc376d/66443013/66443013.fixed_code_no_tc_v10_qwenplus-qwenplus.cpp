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
            // Cycle detected back to node 1, update answer
            ans = min(ans, dist + 1);
            continue;
        }

        if (!seen[neighbor]) {
            dfs(neighbor, dist + 1);
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
        if (!seen.count(a)) seen[a] = false;
        if (!seen.count(b)) seen[b] = false;
    }

    // Start DFS from node 1
    dfs(1, 0);

    if (ans != inf)
        cout << ans << endl;
    else
        cout << "-1" << endl;
}