#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, vis[N], low[N], timer = 0;

bool dfs(int u, int p, int &cycle_length) {
    vis[u] = timer++;
    low[u] = vis[u];
    
    for (int v : g[u]) {
        if (v == p) continue; // Skip the parent node
        if (!vis[v]) { // If v is not visited
            if (dfs(v, u, cycle_length)) {
                return true;
            }
            low[u] = min(low[u], low[v]);
        } else { // If v is visited but not its parent
            low[u] = min(low[u], vis[v]);
        }
        
        // Check if an odd length cycle is found
        if (low[v] >= vis[u]) {
            cycle_length = min(cycle_length, abs(vis[u] - vis[v]));
        }
    }
    return false;
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
    }

    int min_cycle = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, min_cycle)) {
                break; // Found a cycle, no need to check further
            }
        }
    }

    if (min_cycle == INT_MAX || min_cycle % 2 == 0) {
        cout << "-1\n"; // No odd cycle containing vertex 1 or even cycle
    } else {
        cout << min_cycle << "\n";
    }

    return 0;
}