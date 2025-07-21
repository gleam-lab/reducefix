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
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        int pos = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d > dist[pos]) continue;
        for(int i=0; i<(int)G[pos].size(); i++){
            int nex = G[pos][i];
            if(d + 1 < dist[nex]){
                dist[nex] = d + 1;
                pq.push({dist[nex], nex});
            }
        }
    }
    int ans = INF;
    for(int i=1; i<N; i++){
        if(dist[i] != INF && dist[i] % 2 == 0) ans = min(ans, dist[i]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans / 2 + (ans % 2 ? 1 : 0) << endl;
    return 0;
}