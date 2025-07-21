#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u); // Add edge in both directions since it's undirected
    }
    vector<int> dist(N, INF);
    dist[0] = 0; // Start BFS from node 0
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int i = 0; i < G[pos].size(); ++i){
            int next = G[pos][i];
            if(dist[next] == INF){
                dist[next] = dist[pos] + 1;
                que.push(next);
            }
        }
    }
    int ans = INF;
    for(int i = 1; i < N; ++i){
        // If the node has less than 2 neighbors, it is considered valid
        if(G[i].size() < 2){
            ans = min(ans, dist[i]);
        }
    }
    // If no valid node is found, return -1
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl; // Subtract 1 because problem expects answer to be 1-indexed
    return 0;
}