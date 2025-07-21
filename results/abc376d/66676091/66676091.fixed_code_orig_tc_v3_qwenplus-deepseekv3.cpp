#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int s, v;
        cin >> s >> v;
        s--; v--;
        G[s].push_back(v);
    }

    int min_cycle = INT_MAX;
    vector<int> dist(N, -1);
    queue<int> q;
    
    // Perform BFS from node 0 to find shortest cycle
    q.push(0);
    dist[0] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : G[u]) {
            if(v == 0) {
                // Found a cycle back to node 0
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if(min_cycle != INT_MAX) {
        cout << min_cycle << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}