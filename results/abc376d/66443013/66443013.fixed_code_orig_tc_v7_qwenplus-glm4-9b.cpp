#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll n,ll hen){
    seen[n]=true;
    for(auto x:graph[n]){
        if(seen[x]) continue;
        if(x == 1 && hen != 0){ // If the current node is node 1 and hen is not 0, update the answer
            ans = min(ans, hen);
        } else if (x != 1) { // If the current node is not node 1, continue the DFS
            dfs(x, hen + 1);
        }
    }
    seen[n] = false; // Reset the seen flag for backtracking
}

int main(){
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Ensure the graph is undirected
    }
    dfs(1, 0);
    if(ans != inf) cout << ans << endl;
    else cout << "-1" << endl;
}