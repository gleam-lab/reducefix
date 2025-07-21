#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, visited[N], parent[N];

bool dfs(int u, int par) {
    visited[u] = 1;
    parent[u] = par;
    
    for (auto v : g[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) return true;
        } else if (parent[v] != u && parent[v] != -1) {
            int cycle_length = 0;
            int x = u;
            while (x != v) {
                x = parent[x];
                cycle_length++;
            }
            cycle_length++; // Include the last edge to form the cycle
            return true;
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

    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            cout << "Cycle found with length: " << parent[i] << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}