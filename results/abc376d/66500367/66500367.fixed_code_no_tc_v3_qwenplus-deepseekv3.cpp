#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], par[N];

int find_shortest_cycle() {
    int shortest = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (dep[i]) continue;
        queue<int> q;
        q.push(i);
        dep[i] = 1;
        par[i] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (v == par[u]) continue;
                if (!dep[v]) {
                    dep[v] = dep[u] + 1;
                    par[v] = u;
                    q.push(v);
                } else {
                    shortest = min(shortest, dep[u] + dep[v] - 1);
                }
            }
        }
    }
    return shortest == INT_MAX ? -1 : shortest;
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
    
    cout << find_shortest_cycle() << '\n';
    return 0;
}