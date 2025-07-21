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
        for(int nex : G[pos]){
            if(dist[nex] != -1) continue;
            que.push({nex, d+1});
            dist[nex] = d+1;
        }
    }
    int ans = -1;
    for(int i=0; i<N; i++){
        if(dist[i] == -1) continue;
        for(int x : G[i]){
            if(x == 0){
                if(ans == -1 || dist[i] + 1 < ans){
                    ans = dist[i] + 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}