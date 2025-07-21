#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m;
int ans = -1;

// This function returns true if a cycle is found and updates 'ans'
bool dfs(int u, vector<bool>& visited, vector<bool>& in_stack, int depth) {
    visited[u] = true;
    in_stack[u] = true;

    for (int v : g[u]) {
        if (!visited[v]) {
            if (dfs(v, visited, in_stack, depth + 1)) {
                if (u == 1) {
                    ans = depth + 1;
                }
                return true;
            }
        } else if (in_stack[v] && v == 1) {
            // Found a cycle back to node 1
            ans = depth + 1;
            return true;
        }
    }

    in_stack[u] = false;
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> in_stack(n + 1, false);

    dfs(1, visited, in_stack, 0);

    cout << ans << endl;

    return 0;
}