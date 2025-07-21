#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,ll> parent; // To keep track of the parent node in the DFS for backtracking
ll ans=0;
bool found;

void dfs(ll n, ll hen) {
    if (hen > ans) return; // Prune the search if current height is already greater than the answer found

    seen[n] = true;
    for (auto x : graph[n]) {
        if (!seen[x]) {
            if (x == 1) {
                ans = hen; // Update the answer as soon as we reach the end node '1'
                found = true;
                return;
            }
            parent[x] = n; // Save the parent node
            dfs(x, hen + 1);
        }
    }

    // Backtrack
    seen[n] = false;
    if (n != 1) { // We don't need to backtrack from node '1' as it's the end
        graph[parent[n]].erase(remove(graph[parent[n]].begin(), graph[parent[n]].end(), n), graph[parent[n]].end());
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Ensure undirected graph
    }

    seen[1] = true; // Start DFS from node '1'
    dfs(1, 0);

    if (found) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}