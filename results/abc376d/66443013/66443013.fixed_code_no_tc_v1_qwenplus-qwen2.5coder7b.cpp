#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;

// Function to perform DFS and find the minimum distance to node 1
void dfs(ll n, ll dist){
    seen[n] = true; // Mark the current node as visited
    for(auto x : graph[n]){ // Iterate through all neighbors of the current node
        if(seen[x]) continue; // Skip already visited nodes
        if(x == 1){ // If the neighbor is the target node (node 1)
            ans = min(ans, dist + 1); // Update the answer with the minimum distance found so far
            continue;
        }
        dfs(x, dist + 1); // Recur for unvisited neighbors
    }
}

int main(){
    ll n, m;
    cin >> n >> m; // Input number of nodes and edges
    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b; // Input each edge
        graph[a].push_back(b); // Add the edge to the graph
        graph[b].push_back(a); // Since it's an undirected graph, add both directions
        seen[a] = false; // Initialize visit status for all nodes as false
        seen[b] = false;
    }
    dfs(1, 0); // Start DFS from node 1 with initial distance 0
    if(ans != inf) cout << ans << endl; // Output the result if node 1 is reachable
    else cout << "-1" << endl; // Output -1 if node 1 is not reachable
    return 0;
}