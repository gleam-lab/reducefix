#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;
vector<int> g[MAXN];
bool visited[MAXN];

// Function to perform DFS and count connected components
int dfs(int node) {
    if (visited[node]) return 0;
    visited[node] = true;
    int size = 1;
    for (int neighbor : g[node]) {
        size += dfs(neighbor);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    vector<int> component_sizes;

    // Find all connected components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            component_sizes.push_back(dfs(i));
        }
    }

    // If there is only one component, no operations are needed
    if (component_sizes.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Calculate the minimum number of operations needed
    int result = INT_MAX;
    for (int i = 0; i < component_sizes.size(); ++i) {
        for (int j = i + 1; j < component_sizes.size(); ++j) {
            result = min(result, component_sizes[i] + component_sizes[j]);
        }
    }

    cout << result << endl;
    return 0;
}