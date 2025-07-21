#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, vector<ll>> graph;
map<ll, bool> seen;
const ll inf = 1LL << 60;
ll ans = inf;

void dfs(ll n, ll hen, bool &found) {
    seen[n] = true;
    for (auto x : graph[n]) {
        // Ensure that we don't revisit the same node
        if (seen[x]) continue;
        if (x == 1) {
            if (hen != 1) {
                ans = min(ans, hen + 1);
                found = true;
            }
            continue;
        }
        dfs(x, hen + 1, found);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Ensure the graph is bidirectional
    }
    ll start = 1; // Start the DFS from the node '1'
    bool found = false;
    dfs(start, 0, found);
    if (found) cout << ans << endl;
    else cout << "-1" << endl;
}