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

    queue<pair<int, int>> q; // {current node, distance}
    vector<int> dist(n+1, -1);
    vector<int> parent(n+1, -1);
    int min_cycle = INT_MAX;

    q.push({1, 0});
    dist[1] = 0;

    while(!q.empty()){
        auto [u, d] = q.front();
        q.pop();

        for(int v : adj[u]){
            if(v == 1 && d+1 < min_cycle){
                min_cycle = d+1;
            }
            if(dist[v] == -1){
                dist[v] = d+1;
                parent[v] = u;
                q.push({v, d+1});
            }
        }
    }

    if(min_cycle != INT_MAX){
        cout << min_cycle << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}