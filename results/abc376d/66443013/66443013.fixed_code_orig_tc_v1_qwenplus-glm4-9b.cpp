#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll n, ll hen) {
  for(auto x:graph[n]) {
    if(x == 1) {
      if(hen >= 2) {
        ans = min(ans, hen);  // We find a valid path when hen is 2 or more
        return;  // Early return to avoid unnecessary recursion
      }
    } else if(!graph.count(x) || graph[x].empty()) {  // Check if x is not seen or has no edges
      continue;
    } else {
      dfs(x, hen + 1);  // Move to the next level of depth
    }
  }
}

int main() {
  ll n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);  // Ensure the graph is undirected
  }
  dfs(1, 0);  // Start DFS from node 1 with initial depth 0
  if(ans != inf) cout << ans << endl;
  else cout << "-1" << endl;
}