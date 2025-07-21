#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], parent[N];

int findShortestCycle() {
    int shortest_cycle = INT_MAX;
    for (int u = 1; u <= n; ++u) {
        fill(dep, dep + n + 1, -1);
        fill(parent, parent + n + 1, -1);
        queue<int> q;
        q.push(u);
        dep[u] = 0;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int neighbor : g[v]) {
                if (dep[neighbor] == -1) {
                    dep[neighbor] = dep[v] + 1;
                    parent[neighbor] = v;
                    q.push(neighbor);
                } else if (parent[v] != neighbor && parent[neighbor] != v) {
                    shortest_cycle = min(shortest_cycle, dep[v] + dep[neighbor] + 1);
                }
            }
        }
    }
    return (shortest_cycle == INT_MAX) ? -1 : shortest_cycle;
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
        g[v].push_back(u); // Undirected graph needs both directions
    }
    
    int result = findShortestCycle();
    cout << result << '\n';
    return 0;
}