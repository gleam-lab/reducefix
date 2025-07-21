#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    ll min_cycle = LONG_MAX;
    vector<ll> dist(n+1, -1);
    queue<pair<int,int>> q; // {node, parent}

    // Initialize BFS from node 1
    q.push({1, -1});
    dist[1] = 0;

    while(!q.empty()){
        auto [u, parent] = q.front();
        q.pop();

        for(int v : adj[u]){
            if(v == 1 && u != parent){ // Found a cycle back to 1
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if(dist[v] == -1 || (v == 1 && dist[u] + 1 < dist[v])){
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }

    if(min_cycle == LONG_MAX){
        cout << -1;
    } else {
        cout << min_cycle;
    }
    return 0;
}