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
        G[v].push_back(u); // Fix: Add both directions to make it undirected
    }
    vector<int> dist(N, INF);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int neighbor : G[pos]){
            if(dist[neighbor] == INF){
                que.push(neighbor);
                dist[neighbor] = dist[pos] + 1;
            }
        }
    }
    int ans = INF;
    for(int i=1; i<N; i++){
        bool isLeaf = true;
        for(int neighbor : G[i]){
            if(dist[neighbor] != INF) isLeaf = false;
        }
        if(isLeaf) ans = min(ans, dist[i]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}