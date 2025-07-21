#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
const int INF = INT_MAX;

vector<int> adj[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Clear the adjacency list
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    
    // Read edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INF;
    queue<pair<int, int>> q;
    vector<int> dist(n + 1, INF);
    
    // Start BFS from node 1
    q.push({1, 1});
    dist[1] = 1;
    
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                // Found a cycle back to node 1
                min_cycle = min(min_cycle, d);
                continue;
            }
            if(dist[v] > d + 1) {
                dist[v] = d + 1;
                q.push({v, d + 1});
            }
        }
    }
    
    if(min_cycle == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}