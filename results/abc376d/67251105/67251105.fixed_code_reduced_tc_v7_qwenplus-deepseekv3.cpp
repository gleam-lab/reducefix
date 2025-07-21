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
    for(int u = 0; u < N; u++){
        if(dist[u] == -1) continue;
        for(int v : G[u]){
            if(v == 0){
                ans = min(ans, dist[u] + 1);
            }
        }
    }
    
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}