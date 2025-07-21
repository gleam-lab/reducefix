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
            if(dist[nex]!=-1) continue;
            que.push({nex, d+1});
            dist[nex] = d+1;
        }
    }

    // Check if node 0 can reach itself through a cycle (required for answer)
    bool zero_cycle = false;
    for(auto x : G[0]){
        if(x == 0){
            zero_cycle = true;
            break;
        }
    }

    int ans = INF;
    for(int i=1; i<N; i++){
        bool ok = false;
        for(auto x : G[i]){
            if(x == 0) {
                ok = true;
                break;
            }
        }
        if(ok && dist[i] != -1){
            ans = min(ans, dist[i]);
        }
    }

    if(ans == INF || dist[0] == -1){
        cout << -1 << endl;
    } else {
        cout << ans + (zero_cycle ? 0 : 1) << endl;
    }

    return 0;
}