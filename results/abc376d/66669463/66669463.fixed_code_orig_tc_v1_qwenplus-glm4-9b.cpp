#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
};

vector<int> graph[200001];
int n, m;
int depth[200001];
int max_depth = -1;

void dfs(int node, int dep) {
    if (dep > max_depth) {
        max_depth = dep;
        depth[node] = max_depth;
    }
    for (int neighbor : graph[node]) {
        dfs(neighbor, dep + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        depth[i] = -1; // Initialize depth to -1
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    cout << max_depth << endl;
    return 0;
}