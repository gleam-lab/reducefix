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
    // Check if there's a cycle back to node 0 via BFS
    bool has_cycle = false;
    vector<bool> visited(N, false);
    queue<int> cycle_que;
    cycle_que.push(0);
    visited[0] = true;
    while (!cycle_que.empty()) {
        int u = cycle_que.front();
        cycle_que.pop();
        for (int v : G[u]) {
            if (v == 0 && dist[u] > 0) { // Ensure it's not the starting edge itself
                has_cycle = true;
                break;
            }
            if (!visited[v]) {
                visited[v] = true;
                cycle_que.push(v);
            }
        }
        if (has_cycle) break;
    }

    if (!has_cycle) {
        cout << -1 << endl;
        return 0;
    }

    // Find minimum distance to nodes that can reach back to 0
    int ans = INF;
    for(int i = 1; i < N; i++){
        if (dist[i] != -1) {
            for(int v : G[i]) {
                if (v == 0) {
                    ans = min(ans, dist[i]);
                    break;
                }
            }
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl;
    return 0;
}