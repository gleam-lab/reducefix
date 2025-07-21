#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
const int INF = 1e9;
vector<int> g[N];
int n, m;

int findShortestCycle() {
    int shortest = INF;
    
    for (int u = 1; u <= n; ++u) {
        vector<int> dist(n + 1, -1);
        vector<int> parent(n + 1, -1);
        queue<int> q;
        
        dist[u] = 0;
        q.push(u);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int neighbor : g[v]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[v] + 1;
                    parent[neighbor] = v;
                    q.push(neighbor);
                } else if (parent[v] != neighbor && parent[neighbor] != v) {
                    shortest = min(shortest, dist[v] + dist[neighbor] + 1);
                }
            }
        }
    }
    
    return shortest == INF ? -1 : shortest;
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
        g[v].push_back(u);
    }
    
    cout << findShortestCycle() << '\n';
    return 0;
}