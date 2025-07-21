#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    
    // BFS from node 1 to find shortest cycle back to 1
    queue<int> q;
    fill(dist, dist + n + 1, -1);
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                // Found a cycle back to 1
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
    
    // Clean up for potential multiple test cases
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}