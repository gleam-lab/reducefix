#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>> graph;
map<ll,ll> degree;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll n){
    // Mark the node as visited
    seen[n]=true;

    for(auto x:graph[n]){
        if(seen[x]) continue; // Skip if already visited
        if(x == 1) {
            ans = min(ans,degree[n]+1);
        } else {
            degree[x] += degree[n]; // Update the degree of the child node
            dfs(x);
        }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    // Start DFS from node 1 (ensure it's present in the graph)
    if(graph.count(1)) dfs(1);
    // If no valid answer found, set to -1
    if(ans == inf) ans = -1;
    cout<<ans<<endl;
}