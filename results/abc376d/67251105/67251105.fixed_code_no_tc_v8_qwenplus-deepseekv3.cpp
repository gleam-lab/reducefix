#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    
    int ans = INF;
    
    // Check if node 0 has a self-loop (direct cycle)
    for(auto v : G[0]){
        if(v == 0){
            ans = 1;
            break;
        }
    }
    
    if(ans != 1){ // If no self-loop, search for shortest cycle through other nodes
        vector<int> dist(N, INF);
        queue<int> q;
        
        // Initialize distances for nodes directly reachable from 0
        for(auto v : G[0]){
            if(v != 0){
                dist[v] = 1;
                q.push(v);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto v : G[u]){
                if(v == 0){ // Found a path back to 0
                    ans = min(ans, dist[u] + 1);
                    continue;
                }
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}