#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll n, ll hen) {
    // Mark the current node as visited
    seen[n] = true;
    // Explore all adjacent nodes
    for (auto &x : graph[n]) {
        // Skip if the node is node 1 and it's a revisit
        if (x == n && seen[x]) continue;
        // If it's node 1, check if the depth is 1 and update the answer
        if (x == 1) {
            if (hen == 1) {
                ans = min(ans, hen + 1);
            }
            continue;
        }
        dfs(x, hen + 1);
    }
    // Unmark the current node as visited
    seen[n] = false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);  // Add edge from b to a as well
        seen[a] = false;
        seen[b] = false;
    }
    dfs(1, 0);
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}