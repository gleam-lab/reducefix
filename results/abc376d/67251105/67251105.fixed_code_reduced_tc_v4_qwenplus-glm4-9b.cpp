#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u); // Ensure the graph is undirected
    }
    vector<int> dist(N, INF);
    dist[0] = 0; // Starting distance from node 0 is 0
    queue<int> que;
    que.push(0); // Use a queue for BFS
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int i=0; i<(int)G[pos].size(); i++){
            int nex = G[pos][i];
            if(dist[nex] > dist[pos] + 1){
                dist[nex] = dist[pos] + 1;
                que.push(nex);
            }
        }
    }
    int ans = INF;
    for(int i=1; i<N; i++){
        if(dist[i] != INF && !G[i].empty()) { // Check if the node has edges and is reachable
            ans = min(ans, dist[i]);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl; // +1 because the problem seems to be asking for a 1-based index
    return 0;
}