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
    }
    
    // BFS from node 0 to compute shortest distances
    vector<int> dist(N, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int nex : G[pos]){
            if(dist[nex] == -1){
                dist[nex] = dist[pos] + 1;
                que.push(nex);
            }
        }
    }

    // Now look for a cycle back to 0 through any edge to node 0
    int ans = INF;
    for(int i = 1; i < N; ++i){
        // Check if there's an edge from i to 0
        bool hasEdgeTo0 = false;
        for(int neighbor : G[i]){
            if(neighbor == 0){
                hasEdgeTo0 = true;
                break;
            }
        }
        if(hasEdgeTo0 && dist[i] != -1){
            ans = min(ans, dist[i]);
        }
    }

    if(ans == INF){
        cout << -1 << endl;
    } else {
        // The cycle length is the distance to i plus 1 (the edge i->0)
        cout << ans + 1 << endl;
    }

    return 0;
}