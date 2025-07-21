#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], par[N];

int bfs() {
    int shortest_cycle = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) continue;
        
        queue<int> q;
        q.push(i);
        dep[i] = 0;
        par[i] = -1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : g[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    par[v] = u;
                    q.push(v);
                } else if (v != par[u]) {
                    shortest_cycle = min(shortest_cycle, dep[u] + dep[v] + 1);
                }
            }
        }
        
        fill(dep, dep + n + 1, -1);
    }
    return shortest_cycle == INT_MAX ? -1 : shortest_cycle;
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
        g[v].push_back(u); // Add reverse edge for undirected graph
    }
    
    fill(dep, dep + n + 1, -1);
    fill(par, par + n + 1, -1);
    
    cout << bfs() << '\n';
    return 0;
}