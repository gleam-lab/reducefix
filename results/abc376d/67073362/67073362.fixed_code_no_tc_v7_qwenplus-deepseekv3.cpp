#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
const int INF = INT_MAX;
vector<int> adj[N];

int findShortestCycle(int n) {
    int min_cycle = INF;
    
    // For BFS from node 1
    vector<int> dist(n + 1, -1);
    queue<pair<int, int>> q; // {current node, parent}
    
    dist[1] = 0;
    q.push({1, -1});
    
    while (!q.empty()) {
        auto [u, parent] = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (v == 1 && parent != 1) { // Found a cycle back to 1
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if (dist[v] == -1) { // Not visited yet
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }
    
    return (min_cycle == INF) ? -1 : min_cycle;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int result = findShortestCycle(n);
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}