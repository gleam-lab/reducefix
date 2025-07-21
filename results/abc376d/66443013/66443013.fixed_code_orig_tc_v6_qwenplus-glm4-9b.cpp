#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
ll ans=1e18; // Use a large constant instead of 1<<60

void dfs(ll n, ll depth, ll prev){
    if (depth > ans) return; // Prune the search if we've already found a shorter path
    if (n == 1) {
        ans = min(ans, depth);
        return;
    }
    for(auto x : graph[n]){
        if (x != prev) dfs(x, depth + 1, n); // Only go to unvisited nodes that are not the previous node
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dfs(1, 0, -1); // Start DFS from node 1 with initial depth 0 and no previous node
    if (ans == 1e18) cout << "-1" << endl;
    else cout << ans << endl;
}