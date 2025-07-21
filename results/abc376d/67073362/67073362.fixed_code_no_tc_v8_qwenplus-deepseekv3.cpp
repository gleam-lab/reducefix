#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int N = 2e5 + 10;
const int INF = INT_MAX;

vector<int> adj[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INF;
    
    // BFS for each neighbor of node 1
    for (int start : adj[1]) {
        fill(dist, dist + n + 1, INF);
        queue<int> q;
        
        dist[start] = 1;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (v == 1) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    continue;
                }
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    cout << (min_cycle == INF ? -1 : min_cycle) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}