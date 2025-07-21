#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N];

int bfs() {
    int shortest_cycle = INT_MAX;
    for (int start = 1; start <= n; ++start) {
        fill(dep + 1, dep + n + 1, -1);
        queue<pii> q;
        q.push({start, -1});
        dep[start] = 0;
        
        while (!q.empty()) {
            auto [u, parent] = q.front();
            q.pop();
            
            for (int v : g[u]) {
                if (v == parent) continue;
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    q.push({v, u});
                } else {
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
        g[v].push_back(u); // Add edge in both directions for undirected graph
    }
    
    cout << bfs() << '\n';
    return 0;
}