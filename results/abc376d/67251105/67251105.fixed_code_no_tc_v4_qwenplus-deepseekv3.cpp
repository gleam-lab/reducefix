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
    
    int ans = INT_MAX;
    
    // First, check for immediate cycles (0 -> 0)
    for(int v : G[0]) {
        if(v == 0) {
            ans = 1;
            break;
        }
    }
    
    // If not found, perform BFS to find shortest cycle through 0
    if(ans == INT_MAX) {
        vector<int> dist(N, -1);
        queue<int> q;
        
        // Initialize distances for neighbors of 0
        for(int v : G[0]) {
            if(v == 0) continue; // already checked
            dist[v] = 1;
            q.push(v);
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : G[u]) {
                if(v == 0) {
                    ans = min(ans, dist[u] + 1);
                    continue;
                }
                if(dist[v] == -1 || dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}