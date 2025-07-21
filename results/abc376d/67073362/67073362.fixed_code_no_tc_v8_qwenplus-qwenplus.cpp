#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 1e9 + 7;
vector<int> adj[N];

// BFS to find shortest cycle starting from node 1
int findShortestCycle(int n) {
    vector<int> dist(n + 1, INF);
    queue<int> q;
    
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } 
            // If we revisit node 1, we found a cycle
            else if (v == 1) {
                return dist[u] + 1;
            }
        }
    }
    
    return -1; // No cycle found
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <= n) adj[i].clear(); // Clear previous data
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    cout << findShortestCycle(n) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}