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
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u); // Ensure the graph is undirected
    }
    vector<int> dist(N, INF); // Use INF as the initial distance
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0] = 0;
    while(!que.empty()){
        int pos = que.front().first;
        int d = que.front().second;
        que.pop();
        for(int i=0; i<(int)G[pos].size(); i++){
            int nex = G[pos][i];
            if(dist[nex] == INF){
                que.push({nex, d+1});
                dist[nex] = d+1;
            }
        }
    }
    int ans = INF;
    for(int i=1; i<N; i++){
        if(dist[i] != INF && (int)G[i].size() == 1){ // Check if the node has only one connection and is reachable
            ans = min(ans, dist[i]);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl; // Add 1 for the output format
    return 0;
}