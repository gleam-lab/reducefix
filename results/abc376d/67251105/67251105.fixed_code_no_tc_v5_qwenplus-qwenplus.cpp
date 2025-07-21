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

    // BFS from node 0 to calculate shortest distances
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

    // Find shortest cycle that starts and ends at 0
    int ans = INT_MAX;
    for(int i = 1; i < N; i++){
        if (dist[i] != -1) {
            // Check if there is an edge from i back to 0
            for(int neighbor : G[i]){
                if(neighbor == 0){
                    ans = min(ans, dist[i] + 1);
                    break; // No need to check other edges from i
                }
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}