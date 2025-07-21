#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 998244353LL;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    // BFS to find shortest path from node 0 to all nodes
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

    // Find minimum distance from any node with an edge to 0, back to 0 (cycle length)
    int min_cycle_length = 100000000;
    for(int i = 1; i < N; i++){
        for(int neighbor : G[i]){
            if(neighbor == 0 && dist[i] != -1){
                min_cycle_length = min(min_cycle_length, dist[i] + 1); // +1 for the edge back to 0
            }
        }
    }

    cout << (min_cycle_length == 100000000 ? -1 : min_cycle_length) << endl;
    return 0;
}