#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
const int INF = INT_MAX;

vector<int> adj[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Clear the graph
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    
    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INF;
    
    // BFS for each neighbor of node 1 to find shortest cycle
    for (int start : adj[1]) {
        // Initialize distances
        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
        }
        
        queue<int> q;
        q.push(start);
        dist[start] = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    break;
                }
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    if (min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}