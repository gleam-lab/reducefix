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
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0] = 0;
    while(!que.empty()){
        int pos = que.front().first;
        int d = que.front().second;
        que.pop();
        for(int i=0; i<(int)G[pos].size(); i++){
            int nex = G[pos][i];
            if(dist[nex] != -1) continue;
            que.push({nex, d+1});
            dist[nex] = d+1;
        }
    }
    int ans = INF;
    for(int i=0; i<N; i++){
        bool ok = false;
        for(auto x : G[i]){
            if(x == G[i][0]) ok = true; // Check if there is at least one edge
        }
        if(ok) ans = min(ans, dist[i]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans+1 << endl; // This is the correct place to add 1
    return 0;
}