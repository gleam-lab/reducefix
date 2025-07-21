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
        G[v].push_back(u); // Add the reverse edge if the graph is undirected
    }
    vector<int> dist(N, INF);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int nx : G[pos]){
            if(dist[nx] == INF){
                que.push(nx);
                dist[nx] = dist[pos] + 1;
            }
        }
    }
    // Find the minimum distance to a vertex that is not isolated
    long long ans = INF;
    for(int i = 1; i < N; i++){
        if(dist[i] != INF && dist[i] != INF - 1){ // INF - 1 is used to represent unreachable vertices
            ans = min(ans, dist[i]);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}