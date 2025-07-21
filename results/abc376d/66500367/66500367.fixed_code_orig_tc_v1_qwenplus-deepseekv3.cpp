#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dist[N], parent[N];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;
    
    int min_cycle = INT_MAX;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (parent[u] != v) {
                min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
            }
        }
    }
    
    return min_cycle == INT_MAX ? -1 : min_cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Assuming undirected graph based on input
    }
    
    int result = INT_MAX;
    for (int i = 1; i <= n && i <= 100; i++) { // Limit to first 100 nodes for efficiency
        fill(dist, dist + n + 1, -1);
        fill(parent, parent + n + 1, -1);
        int cycle_len = bfs(i);
        if (cycle_len != -1) {
            result = min(result, cycle_len);
        }
    }
    
    cout << (result == INT_MAX ? -1 : result) << '\n';
    return 0;
}