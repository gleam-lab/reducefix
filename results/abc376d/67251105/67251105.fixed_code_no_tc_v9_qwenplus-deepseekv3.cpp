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
    
    int ans = INT_MAX;
    // Check direct neighbors of 0 for a 2-node cycle
    for(int nex : G[0]){
        if(nex == 0){
            ans = 1;
            break;
        }
    }
    
    if(ans != 1){  // If no 2-node cycle found, check longer cycles
        for(int i=1; i<N; i++){
            if(dist[i] == -1) continue;  // Skip unreachable nodes
            for(int nex : G[i]){
                if(nex == 0){
                    ans = min(ans, dist[i] + 1);
                    break;
                }
            }
        }
    }
    
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}