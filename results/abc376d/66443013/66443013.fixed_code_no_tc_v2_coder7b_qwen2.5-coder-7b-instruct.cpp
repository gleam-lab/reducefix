#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
set<ll>seen;
const ll inf=1LL<<60;
ll ans=inf;

// Function to perform DFS and detect cycle length
void dfs(ll node, ll parent, ll depth) {
    if(depth > ans) return; // If current path exceeds known minimum, stop exploring further
    if(seen.find(node) != seen.end()) { // If node is already visited and not the parent, a cycle is detected
        ans = min(ans, depth - seen[node]); // Update the answer with the minimum cycle length
        return;
    }
    seen.insert({node, depth}); // Mark the node with its depth in the path
    for(auto neighbor: graph[node]) {
        if(neighbor == parent) continue; // Skip the parent to avoid revisiting it immediately
        dfs(neighbor, node, depth + 1); // Recur for all other neighbors
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1, 0, 0); // Start DFS from node 1 with no parent and depth 0

    if(ans == inf) cout << "-1" << endl; // If no cycle found, output -1
    else cout << ans << endl; // Otherwise, output the minimum cycle length

    return 0;
}