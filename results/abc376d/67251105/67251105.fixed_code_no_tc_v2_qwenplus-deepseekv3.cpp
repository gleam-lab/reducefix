#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    
    // Check if node 0 has self-loop (direct cycle)
    for (int v : G[0]) {
        if (v == 0) {
            min_cycle = 1;
            break;
        }
    }
    
    // BFS to find shortest cycle through other nodes
    vector<int> dist(N, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : G[u]) {
            if (v == 0 && dist[u] + 1 >= 1) {  // Found a cycle back to 0
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if (min_cycle == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
    
    return 0;
}