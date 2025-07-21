#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], parent[N];

int find_shortest_cycle() {
    int shortest_cycle = INT_MAX;
    
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        fill(dep, dep + n + 1, -1);
        fill(parent, parent + n + 1, -1);
        
        q.push(i);
        dep[i] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : g[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v && parent[v] != u) {
                    shortest_cycle = min(shortest_cycle, dep[u] + dep[v] + 1);
                }
            }
        }
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
        g[v].push_back(u); // Add reciprocal edge for undirected graph
    }
    
    int result = find_shortest_cycle();
    cout << result << '\n';
    
    return 0;
}