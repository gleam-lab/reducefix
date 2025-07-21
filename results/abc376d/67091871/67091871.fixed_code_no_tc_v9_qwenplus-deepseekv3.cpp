#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<int> b[n+1];
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    
    vector<int> dist(n+1, -1);
    queue<pair<int,int>> q; // {node, parent}
    q.push({1, -1});
    dist[1] = 0;
    int mn = INT_MAX;
    
    while(!q.empty()){
        auto [x, parent] = q.front();
        q.pop();
        
        for(int neighbor : b[x]){
            if(neighbor == 1 && x != 1){ // found a cycle back to 1
                mn = min(mn, dist[x] + 1);
            }
            if(dist[neighbor] == -1 && neighbor != 1){ // not visited and not starting node
                dist[neighbor] = dist[x] + 1;
                q.push({neighbor, x});
            }
        }
    }
    
    if(mn == INT_MAX){
        cout << -1;
    } else {
        cout << mn;
    }
    
    return 0;
}